
using System;

namespace openFile
{
    public partial class Form1 : Form
    {

        

        public Form1()
        {
            InitializeComponent();
        }





         private void ReadFile_Click(object sender, EventArgs e)
        {
           

            try
            {


                int count = 0;
                int numbers = 0;
                int sum = 0;

                OpenFileDialog openFileDialog = new OpenFileDialog();
                openFileDialog.ShowDialog();
                string filePath = openFileDialog.FileName;
                StreamReader streamReader = new StreamReader(filePath);

                while (!streamReader.EndOfStream)
                {
                    numbers = Convert.ToInt32(streamReader.ReadLine());
                    sum = sum + numbers;
                    NumbersFromFile.Items.Add(numbers.ToString());
                    count++;
                }

                sumLabel.Text = "Sum of all numbers : " + sum.ToString();
                totalNum.Text = "How many random numbers : " + count.ToString();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void endButton_Click(object sender, EventArgs e)
        {
            Close();
        }

    

       
}
}

