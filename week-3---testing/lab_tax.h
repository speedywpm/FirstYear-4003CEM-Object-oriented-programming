/**
 * Calculate the personal tax allowance of a person 
 * under the UK tax system
 * 
 * @param salary annual salary in GBP
 * @return personnal allowance amount in GBP
 */
int personal_allowance( int salary )
{
  float pallowance=11500;
  if(salary>100000 && salary>0)
  {
    pallowance=11500-((salary-100000)*0.5);
    return pallowance;
  }
  else
  {
    return pallowance;
  }
}

/**
 * Calculate the income tax of a person 
 * under the UK tax system
 * 
 * @param salary annual salary in GBP
 * @return personnal allowance amount in GBP
 */
float income_tax( float salary )
{
  int taxedincome=salary-personal_allowance(salary);
  int finalincome=taxedincome;
  if(taxedincome>0 && taxedincome<=37500)
  {
    finalincome=taxedincome*0.2;
    return finalincome;
  }
  else if(taxedincome>0 && taxedincome>37500 && taxedincome<=150000)
  {
    finalincome=finalincome-37500;
    finalincome=(37500*0.2)+(finalincome*0.4);
    return finalincome;
  }
  else if(taxedincome>0 && taxedincome>150000)
  {
    finalincome=finalincome-150000;
    finalincome=(37500*0.2)+(125000*0.4)+(finalincome*0.45);
    return finalincome;
  }
  else{
    return 0;
  }
}
