using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;



namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        int[] history1 = new int[50];//总共题目
        int[] history2 = new int[50];//做对题目
        int[] history3 = new int[50];//做错题目
        int historytime = 0;
        string current;
        int isstart = 0;
        int mode = 0;
        int count = 0;
        int time = 20;
        int num;
        int ok = 0;
        public Form1()
        {
            InitializeComponent();
            textBox1_SetDefaultText();
            label6.Text = "";
        }

        public static string execCMD(string command)
        {
            System.Diagnostics.Process pro = new System.Diagnostics.Process();
            pro.StartInfo.FileName = "cmd.exe";
            pro.StartInfo.UseShellExecute = false;
            pro.StartInfo.RedirectStandardError = true;
            pro.StartInfo.RedirectStandardInput = true;
            pro.StartInfo.RedirectStandardOutput = true;
            pro.StartInfo.CreateNoWindow = true;
            //pro.StartInfo.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
            pro.Start();
            pro.StandardInput.WriteLine(command);
            pro.StandardInput.WriteLine("exit");
            pro.StandardInput.AutoFlush = true;
            //获取cmd窗口的输出信息
            //string output = pro.StandardOutput.ReadToEnd();
            string output = pro.StandardOutput.ReadLine();
            output = pro.StandardOutput.ReadLine();
            output = pro.StandardOutput.ReadLine();
            output = pro.StandardOutput.ReadLine();
            output = pro.StandardOutput.ReadLine();
            pro.WaitForExit();//等待程序执行完退出进程
            pro.Close();
            return output;

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_SetDefaultText()
        {
            textBox1.Text = "10";
        }



        //public string replace_all(string str, const string old_value, const string new_value)   
        //{   
        //    while(true)  
        //    {   
        //         string::size_type pos(0);   
        //        if((pos=str.find(old_value)) != string::npos  )   
        //        { 
        //            str.replace(pos, old_value.length(),new_value); 
        //        }  
        //             else 
        //            { break; }
        //    }   
        //    return  str;   
        //}
        



private void button3_Click(object sender, EventArgs e)
        {
            
            ok = 0;
            string t = textBox1.Text;
            num = int.Parse(t);
            if(num<1||num>=1000)
            {
                MessageBox.Show("请输入0到1000之间的整数");
                return;
            }
            count = 0;
            timer1.Start();
            
            if (radioButton1.Checked)
            {
                mode = 1;
                current = execCMD("chuti.exe 1");
            }
            else
            {
                mode = 2;
                current = execCMD("chuti.exe 2");
            }

            label10.Text = current;
            if(mode==1)
            {
                current = current.Replace("^", "**");
      
            }
            if (isstart==0)
            {
                isstart = 1;
                
                history1[0] = num;
            }
            else
            {
                historytime++;
            }
            history1[historytime] = num;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            string correct;
            count++;
            label6.Text = (time - count).ToString() + "秒";
            if(count==time)
            {
                timer1.Stop();
                correct = execCMD("jieti.exe "+"2"+" "+current);
                label11.Text = "时间到，正确答案为：" + correct;
                history3[historytime]++;
                count = 0;
                timer1.Start();
            }
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            if(isstart==0)
            {
                MessageBox.Show("请先点击开始按钮");
                return;
            }
            string correct;
            count = 0;
            correct= execCMD("jieti.exe " + "2"+" "+current);
            if (correct.Equals(textBox2.Text))
            {
                label11.Text = "正确";
                history2[historytime]++;
            }
            else
            {
                
                label11.Text = "错误，正确答案为：" + correct;
                history3[historytime]++;
            }
            ok++;
            if(ok==num)
            {
                int notanswered = history1[historytime] - history2[historytime] - history3[historytime];
                MessageBox.Show("答题完成！\n题目总数：" + history1[historytime] + "\n答对题目：" + history2[historytime] + "\n答错或超时题目：" + history3[historytime]+"\n未答题目："+ notanswered);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            for(int i=0;i<historytime+1;i++)
            {
                int notanswered = history1[i] - history2[i] - history3[i];
                MessageBox.Show("第"+(i+1)+"次答题\n"+"题目总数：" + history1[i] + "\n答对题目：" + history2[i] + "\n答错或超时题目：" + history3[i] + "\n未答题目：" + notanswered);
            }
        }
    }
}
