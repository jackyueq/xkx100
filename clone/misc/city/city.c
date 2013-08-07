// Last Modified by sir on 4.10.2002
// Ҫ����ĳ�����У�����ʥּ������ְ������
// ����֪���⣬��ĸ���ֻ�ܿ���ĳ����ָ����
// ��������һЩѲ����ר�������̡�����ָ����
// ��Ȼ�ֺ����ƻ�����ָ����
// topten���ڳ�͢�������ۡ�
// title������ҡ�
// city : �ۺ�����    city_level  ���Ͷ���   ���Ͷ���  ���Ͷ���  С�Ͷ���
//         �˿�       people       800��      500��    300��     100��
//                   ����ָ�����   8000       5000     3000      1000
//         ũҵ       farming     ���� + ����   �����˿� ��������
//         �ΰ�       peace       �� + ��ʶ   �������� 
//         ˮ��       water       ���� + ����   �������� 
//         ��ҵ       business    ��Ե + ��ò   �����˿� ��������
//         ����       technology  ���� + ����   ���ӿ����ٶ�
//         ˰��       tax_rate    0-100 ֮��    
//                    0-15  ֮��   �ǳ����� �����˿� ��������
//                    15-30 ֮��    ����    �����˿� ���Ҳ���
//                    30-40 ֮��   ΢��Թ�� �˿ڲ���  �������� ũҵ,�ΰ��ܵ��ƻ� 
//                    40-60 ֮��   Թ���ص�  �˿ڼ��� �������� ũҵ,�ΰ�,��ҵ�ܵ��ƻ� 
//                    60-80 ֮��   ��Թ����  �˿ڴ�� ���ҿ� ����ָ�����ܵ��ƻ�
//                    80-100֮��   ��������  ���Ĳ��� ����ָ������� 
//         ����       fealty      0-100֮��
//    ��ò per  ���� str �� dex ��Ե kar ���� sta 
//    ���� int  ��ʶ cor ���� cps ���� con ���� spi

#ifndef CITYDATA
#define CITYDATA "/data/city/"  //�ļ���ŵ�ַ
#endif
#define NAMEOFCITY "yangzhou"  //Ҫ�����ĳ�����
#define CNAMEOFCITY "����"     //���ĳ�����
#define FILE_PATH CITYDATA + NAMEOFCITY
#define LEVEL_OF_CITY "���Ͷ���"  //�ۺ�����
#define LEVEL 500   //���е���ʼ��ģ
#define MAX_LEVEL 800  //���е�����ģ

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

int do_kaifa(string);

void create()
{	set_name(HIY"�ٸ�ͨ��"NOR, ({ "guanfu tonggao", "tonggao"}) );
        set("long","����һ�ż�¼"+CNAMEOFCITY+"��������Ĺٸ�ͨ�档\n
��鿴Ŀǰ����������� help ms_city �˽���������\n");
	set("LAST_KAIFA_PLAYER","none of us"); //��󿪷������е����
        set("city_name", NAMEOFCITY); //������
	set("city_level", LEVEL_OF_CITY);// �ۺ�����
	set("fealty", LEVEL/10);  // ����
	set("tax_rate",LEVEL/10); // ˰��
	set("people", LEVEL*10000);	// �˿�
	set("water", LEVEL*10); // ˮ�� 
	set("water_pro", LEVEL*2); // ˮ��������  
	set("peace", LEVEL*10);  // �ΰ�
	set("peace_pro", LEVEL*2);
	set("farming", LEVEL*10); // �Ƿ�
	set("farming_pro", LEVEL*2);
	set("business", LEVEL*10); // ��ҵ
	set("business_pro", LEVEL*2);
	set("technology", LEVEL*10); // ����
	set("technology_pro", LEVEL*2);
	set("no_get", 1);
	set("unit", "��");
	restore();
}
	
	
	
string query_save_file()
{
	return FILE_PATH;	
}


void init()
{
	add_action("do_kaifa", "kaifa"); 
	add_action("do_chakan","chakan");
	add_action("do_tax","tax");			
}
//int do_chakan()
string long()
{

	string msg;
	object ob;
	ob=this_object();
	msg=HIC"���һ�Źٸ�ͨ����������˱��ǵĿ������: \n"+
	HIY"��������������������������������������������������������������������������\n"NOR;
        msg+=sprintf(HIC"\n ����:" HIY "%8s" NOR HIC"\t\t���й�ģ: " HIY "%8s\n" NOR,
        CNAMEOFCITY, ob->query("city_level"),);
        msg+=sprintf(HIC"\n ˰��:  " HIW "%5d" NOR HIC"\t\t�����˿�: " HIG "%8d\n" NOR,
        ob->query("tax_rate"), ob->query("people"),);
        msg+=sprintf(HIC"\n �ΰ�: " HIW "%8d" NOR HIC"\t\t�ΰ�ָ��: " HIG "%8d\n" NOR,
        ob->query("peace"), ob->query("peace_pro"),);
        msg+=sprintf(HIC"\n ��ҵ: " HIW "%8d" NOR HIC"\t\t��ҵָ��: " HIG "%8d\n" NOR,
        ob->query("business"), ob->query("business_pro"),);
        msg+=sprintf(HIC"\n ũҵ: " HIW "%8d" NOR HIC"\t\tũҵָ��: " HIG "%8d\n" NOR,
        ob->query("farming"), ob->query("farming_pro"),);
        msg+=sprintf(HIC"\n ˮ��: " HIW "%8d" NOR HIC"\t\tˮ��ָ��: " HIG "%8d\n" NOR,
        ob->query("water"), ob->query("water_pro"),);
        msg+=sprintf(HIC"\n ����: " HIW "%8d" NOR HIC"\t\t����ָ��: " HIG "%8d\n" NOR,
        ob->query("technology"), ob->query("technology_pro"),);
	msg+=HIY"��������������������������������������������������������������������������\n"NOR;
	return msg;
}

int do_kaifa(string arg)
{
	
	object ob = this_object();
	object me = this_player();
	string msg;
	int pro_num, lvl_num,add_num,me_score,me_balance;
	int ob_people,ob_taxrate,ob_technology,ob_fealty;
//	kaifa,money,i;

        me_score=(int)me->query("score");
        me_balance=(int)me->query("balance");
        ob_people=(int)ob->query("people");
        ob_taxrate=(int)ob->query("tax_rate");
        ob_technology=(int)ob->query("technology")/100;
/*
	if(! me->query("CITY_KAIFA")))
		return notify_fail("��û�еõ�����������ɣ��޷�Э��������͢�������̡�\n");
	if( me->query("CITY_KAIFA/name")!=ob->query("city_name") )
		return notify_fail("��ҪЭ�������ĳ��к���������ɣ�\n");
*/
//��������С��1000�Ͳ��ü�������	
         
	if (me_score<1000)
	        return notify_fail("��Ľ����������������Ƕ���۵�����������!\n");
//���С��100 gold �Ͳ��ü�������
	if(me_balance<1000000)
	        return notify_fail("��Ĵ������޷����㿪������Ҫ���ʽ�Ҫ��!\n");
        if (ob->query_temp("busy"))
		return notify_fail("���˸��¹���������Ժ�........\n");
	if( !arg || ( arg!= "ˮ��" && arg!="ũҵ"
	          && arg!="�ΰ�" && arg!="��ҵ" && arg!="����"))
	        return notify_fail("��Ҫ����ʲô��\n"); 
//   ��ҵ business    ��Ե + ��ò + ���Ǽ���ֵ  �����˿� ��������
	if( arg=="��ҵ")
	   { 
	      tell_object(me,"��˼��������������ʼЭ���ٸ�����"+CNAMEOFCITY+"����ҵ����Ⱥ����ɣ�\n");
	      pro_num = (int)ob->query("business_pro");
	      lvl_num = (int)ob->query("business");
	      if(lvl_num >= MAX_LEVEL*10)
	        { 
	         return notify_fail(CNAMEOFCITY+"����ҵ�Ѿ��㹻�����ˣ����������ȥ����������Ŀ�ˣ�\n"); 
	        }
	      else
	      { 
	      	add_num = (int)me->query("per")+(int)me->query("kar");
                add_num = add_num + random(ob_technology);
	        pro_num=pro_num+add_num;
	        if (pro_num>=lvl_num)
	            {
	             lvl_num+=1;
	             pro_num = pro_num - lvl_num;
	             message("channel:sys", HIY"�����š�"HIG+CNAMEOFCITY+"����ҵ��"+me->query("name")+"��Э�������±��Խ��Խ�����ˣ�\n"NOR, users());
                     ob_people=ob_people+lvl_num*(1+random(3));
                     if(ob_fealty>=5) ob_fealty-=random(5);
	             }
//	         ob->set("people",ob_people);
//	         ob->set("fealty",ob_fealty);
	         ob->set("business_pro",pro_num);
	         ob->set("business",lvl_num);
		 message_vision( HIW"���е���ҵָ������ˡ�\n"NOR,me);
		} 
	   }
//    ũҵ       farming     ���� + ����+ ���Ǽ���ֵ   �����˿� ��������
	if( arg=="ũҵ")
	   { 
	      tell_object(me,"��˼��������������ʼЭ���ٸ�����"+CNAMEOFCITY+"��ũҵ����Ⱥ����ɣ�\n");
	      pro_num = (int)ob->query("farming_pro");
	      lvl_num = (int)ob->query("farming");
	      if(lvl_num >= MAX_LEVEL*10)
	        { 
	         return notify_fail(CNAMEOFCITY+"��ũҵ�Ѿ��㹻�����ˣ����������ȥ����������Ŀ�ˣ�\n"); 
	        }
	      else
	      { 
	      	add_num = (int)me->query("str")+(int)me->query("sta");
                add_num = add_num + random(ob_technology);
	        pro_num=pro_num+add_num;
	        if (pro_num>=lvl_num)
	            {
	             lvl_num+=1;
	             pro_num = pro_num - lvl_num;
	             message("channel:sys", HIY"�����š�"HIG+CNAMEOFCITY+"��ũ����"+me->query("name")+"��Э�������±��Խ��Խ�����ˣ�\n"NOR, users());
                     ob_people=ob_people+lvl_num*(1+random(3));
                     if(ob_fealty>=5) ob_fealty-=random(5);;
	             }
//	         ob->set("people",ob_people);
//	         ob->set("fealty",ob_fealty);
	         ob->set("farming_pro",pro_num);
	         ob->set("farming",lvl_num);
		 message_vision( HIY"���е�ũҵָ������ˡ�\n"NOR,me);
	        }	 
	   }	   
//   �ΰ�   peace   �� + ��ʶ+ ���Ǽ���ֵ   �������� 
	if( arg=="�ΰ�")
	   { 
	      tell_object(me,"��˼��������������ʼЭ���ٸ�����"+CNAMEOFCITY+"���ΰ�����Ⱥ����ɣ�\n");
	      pro_num = (int)ob->query("peace_pro");
	      lvl_num = (int)ob->query("peace");
	      if(lvl_num >= MAX_LEVEL*10)
	        { 
	         return notify_fail(CNAMEOFCITY+"���ΰ��Ѿ��㹻�����ˣ����������ȥ����������Ŀ�ˣ�\n"); 
	        }
	      else
	      { 
	      	add_num = (int)me->query("dex")+(int)me->query("cor");
                add_num = add_num + random(ob_technology);
	        pro_num=pro_num+add_num;
	        if (pro_num>=lvl_num)
	            {
	             lvl_num+=1;
	             pro_num = pro_num - lvl_num;
	             message("channel:sys", HIY"�����š�"HIG+CNAMEOFCITY+"���ΰ���"+me->query("name")+"��Э�������±��Խ��Խ�����ˣ�\n"NOR, users());              
                     if(ob_fealty<100) ob_fealty+=random(5);
                     if(ob_fealty>100) ob_fealty=100;
	             }
//	         ob->set("fealty",ob_fealty);
	         ob->set("peace_pro",pro_num);
	         ob->set("peace",lvl_num);
		 message_vision( HIC"���е��ΰ�ָ������ˡ�\n"NOR,me);
	        }	 
	   }	 
//    ˮ��  water       ���� + ����+ ���Ǽ���ֵ   �������� 
	if( arg=="ˮ��")
	   { 
	      tell_object(me,"��˼��������������ʼЭ���ٸ�����"+CNAMEOFCITY+"��ˮ������Ⱥ����ɣ�\n");
	      pro_num = (int)ob->query("water_pro");
	      lvl_num = (int)ob->query("water");
	      if(lvl_num >= MAX_LEVEL*10)
	        { 
	         return notify_fail(CNAMEOFCITY+"��ˮ���Ѿ��㹻�����ˣ����������ȥ����������Ŀ�ˣ�\n"); 
	        }
	      else
	      { 
	      	add_num = (int)me->query("con")+(int)me->query("cps");
                add_num = add_num + random(ob_technology);
	        pro_num=pro_num+add_num;
	        if (pro_num>=lvl_num)
	            {
	             lvl_num+=1;
	             pro_num = pro_num - lvl_num;
	             message("channel:sys", HIY"�����š�"HIG+CNAMEOFCITY+"��ˮ����"+me->query("name")+"��Э�������±��Խ��Խ�����ˣ�\n"NOR, users());              
                     if(ob_fealty<100) ob_fealty+=random(5);
                     if(ob_fealty>100) ob_fealty=100;
	             }
//	         ob->set("fealty",ob_fealty);
	         ob->set("water_pro",pro_num);
	         ob->set("water",lvl_num);
		 message_vision( HIC"���е�ˮ��ָ������ˡ�\n"NOR,me);
	        }	 
	   }	
//  ����   technology  ���� + ����   ���ӿ����ٶ�	
	if( arg=="����")
	   { 
	      tell_object(me,"��˼��������������ʼЭ���ٸ�����"+CNAMEOFCITY+"�ļ�������Ⱥ����ɣ�\n");
	      pro_num = (int)ob->query("technology_pro");
	      lvl_num = (int)ob->query("technology");
	      if(lvl_num >= MAX_LEVEL*10)
	        { 
	         return notify_fail(CNAMEOFCITY+"�ļ����Ѿ��㹻�����ˣ����������ȥ����������Ŀ�ˣ�\n"); 
	        }
	      else
	      { 
	      	add_num = (int)me->query("int")+(int)me->query("spi");
                add_num = add_num + random(ob_technology);
	        pro_num=pro_num+add_num;
	        if (pro_num>=lvl_num)
	            {
	             lvl_num+=1;
	             pro_num = pro_num - lvl_num;
	             message("channel:sys", HIY"�����š�"HIG+CNAMEOFCITY+"�ļ�����"+me->query("name")+"��Э���о��±��Խ��Խ�Ƚ��ˣ�\n"NOR, users());                            
	             }
	         ob->set("technology_pro",pro_num);
	         ob->set("technology",lvl_num);
	         message_vision( HIB"���еļ���ָ������ˡ�\n"NOR,me);
		 
	        }	 
	   }	    	    	   
//ÿ��ִ�п���ָ���Ҫ���ǵ�����˰�ʶԱ��ֿ�����Ӱ�� �����о����е㶯̬�� �Ǻ�
//         0-15  ֮��   �ǳ����� �����˿� ��������
//         15-30 ֮��    ����    �����˿� ���Ҳ���
//      30-40 ֮��   ΢��Թ�� �˿ڲ���  �������� ũҵ,�ΰ��ܵ��ƻ� 
//      40-60 ֮��   Թ���ص�  �˿ڼ��� �������� ũҵ,�ΰ�,��ҵ�ܵ��ƻ�
//      60-80 ֮��   ��Թ����  �˿ڴ�� ���ҿ� ����ָ�����ܵ��ƻ�
//      80-100֮��   ��������  ���Ĳ��� ����ָ������� 
       if( ob_taxrate>=0&&ob_taxrate<=15) 
           { 
             if(ob_fealty<100) ob_fealty+=random(5);
             if(ob_fealty>100) ob_fealty=100;
             if(ob_people<MAX_LEVEL*10000)
             ob_people=ob_people+(100-ob_taxrate)*(10+random(5));
             message_vision( MAG"���ڳ��е�˰�ʶ����൱�ͣ�������շǳ����⣬���кܶ���ص��˿�������ı����\n"NOR,me);
            }
           
       else if( ob_taxrate>=16&&ob_taxrate<=30)
            {  
             if(ob_people<MAX_LEVEL*10000)
             ob_people=ob_people+(100-ob_taxrate)*(10+random(5));
             message_vision( GRN"���ڳ��е�˰�ʶ�����Խϵͣ����ջ������⣬������һЩ��ص��˿�������ı����\n"NOR,me);
             }

       else if( ob_taxrate>=31&&ob_taxrate<=40)
             {
               if(ob_fealty>=5) ob_fealty-=random(5);
               pro_num = (int)ob->query("farming_pro");
               lvl_num = (int)ob->query("farming");         
               if (pro_num > 100)
                   { 
                      pro_num = (int)pro_num-random(100);
                      ob->set("farming_pro",pro_num);
                    }                                      
               pro_num = (int)ob->query("peace_pro");          
               if (pro_num > 100)
                   { 
                      pro_num = (int)pro_num-random(100);
                      ob->set("peace_pro",pro_num);
                    }      
               message_vision( CYN"���е�һЩ����Ϊ�ٸ���˰�ʶ��Ĳ�̫����΢��Թ�ԣ������ڳ��﷢��С͵��һЩ��Ը�����ũ��\n"NOR,me);
               }
        else if( ob_taxrate>=41&&ob_taxrate<=60)
             {
             	if(ob_fealty>=5) ob_fealty-=random(5);
             	ob_people=ob_people-ob_taxrate*(10+random(3));
             	pro_num = (int)ob->query("farming_pro"); 
             	if (pro_num > 100)
                   { 
                      pro_num = (int)pro_num-random(100);
                      ob->set("farming_pro",pro_num);
                    }  
                 pro_num = (int)ob->query("peace_pro");          
                 if (pro_num > 100)
                    { 
                      pro_num = (int)pro_num-random(100);
                      ob->set("peace_pro",pro_num);
                     }    
                 pro_num = (int)ob->query("business_pro");          
                 if (pro_num > 100)
                     { 
                      pro_num = (int)pro_num-random(100);
                      ob->set("business_pro",pro_num);
                     }     
             	message_vision( YEL"���а���Թ���ص����󲿷�����Ҳ��Ϊ�ٸ��յ�˰̫���ˣ������ڳ��и���С�ƻ�������Թ�Թٸ��Ĳ�����\n"NOR,me);
             	}
         else if( ob_taxrate>=61&&ob_taxrate<=80)
             {
             	if(ob_fealty>=5) ob_fealty-=random(5); 
             	ob_people=ob_people-ob_taxrate*(10+random(6));            	
             	if ((int)ob->query("farming")> 5&& random(2)==1)  
             	     ob->add("farming",-1);                     
                if ((int)ob->query("water")> 5&& random(2)==1)  
             	     ob->add("water",-1); 
             	if ((int)ob->query("business")> 5&& random(2)==1)  
             	     ob->add("business",-1); 
             	if ((int)ob->query("technology")> 5&& random(2)==1)  
             	     ob->add("technology",-1); 
             	if ((int)ob->query("peace")> 5&& random(2)==1)  
             	     ob->add("peace",-1);                   	          
             	message_vision( BLU"������Թ���ڣ�����һ����Ϊ�ٸ��յ�˰̫���ˣ����𽥶�����ĵط���Աʧȥ���ġ�\n"NOR,me);
             }  
        else
             {
             	if(ob_fealty>=5) ob_fealty-=random(5);
             	ob_people=ob_people-ob_taxrate*(10+random(9));             	
             	if ((int)ob->query("farming")> 5&& random(2)==1)  
             	     ob->add("farming",-2);                     
                if ((int)ob->query("water")> 5&& random(2)==1)  
             	     ob->add("water",-2); 
             	if ((int)ob->query("business")> 5&& random(2)==1)  
             	     ob->add("business",-2); 
             	if ((int)ob->query("technology")> 5&& random(2)==1)  
             	     ob->add("technology",-2); 
             	if ((int)ob->query("peace")> 5&& random(2)==1)  
             	     ob->add("peace",-2);                   	          
             	message_vision( RED"�������ڻ������а����޷����ܹٸ����̰����׷ױ������硣\n"NOR,me);
             	}  
// ÿ��ִ��ָ������50�Ľ������� ��һ���Ĵ��뱾�ǵ�˰���й� ���˰�ʴ�100�Ͳ���Ǯ��
        me_score = me_score-50;
        me_balance = me_balance-2000*(100-ob_taxrate);
        me->set("score",me_score);
        me->set("balance",me_balance);
//��ִֹ�й����г��ָ��˿� ������ֵ������Χ
        if( ob_people<0) ob_people=1;
        ob->set("people",ob_people);
        if (ob_fealty<0) ob_fealty=0;
        if (ob_fealty>100) ob_fealty=100;
        ob->set("fealty",ob_fealty);	      
        save();
        ob->set_temp("busy",1);
	remove_call_out("enough_rest");
//1���ȡ��busy
	call_out("enough_rest", 1);
	return 1;
}
int do_tax(string arg)
{  int ob_taxrate,taxrate;
   object ob=this_object();
   if (ob->query_temp("busy"))
	return notify_fail("���˸��¹���������Ժ�........\n");
   if( !arg
        ||      !sscanf(arg, "%d", taxrate) )
      return notify_fail("���뽫˰�ʶ�Ϊ���٣�\n");
   if(taxrate>100||taxrate<0)
      return notify_fail("˰��ֻ����0��100֮�䣡\n");
   ob_taxrate=taxrate;
   ob->set("tax_rate",ob_taxrate);
   save();
   ob->set_temp("busy",1);
   remove_call_out("enough_rest");
//1���ȡ��busy
   call_out("enough_rest", 1);
   return 1;
}
    
void enough_rest()
{
	delete_temp("busy");
}

