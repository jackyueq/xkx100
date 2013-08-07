// Last Modified by winder on Apr. 25 2001
// �ƽ�ϵͳ��������

#include <ansi.h>

void copy_npc();
string query_site();
int query_children(string arg);
void verdict_time();
void set_hj_startT(int i);
int query_hj_startT();
void juedou();

string *factions=({
  "������",
  "�䵱��",
  "������",
  "��ɽ��",
  "ȫ���",
  "��ң��",
  "����",
  "������"
});
string faction;     //��Ź��������
int Cnpcend, count = 0;
int hj_startT = 0;
object lead;

//�ƽ�ϵͳ������������
void disaster(int sum)
{
  count = sum;
  LOGIN_D->set_dienpc(-1);
  set_hj_startT(time());
  faction = factions[count];
  message("channel:snow", HIM"��ҥ�ԡ�������֯�ĵ�"+chinese_number(count+1)+"��Ŀ����Ѫϴ��"HIR+faction+HIM"����\n"NOR, users());
  message("channel:snow",HIC"��"+HIM MUD_NAME+HIC"�����ڴ�е�ǰ�������ڿ�ʼ�������״̬���κ��˲����������ӣ�\n"NOR, users());

  call_out("copy_npc",0);
}

//����EXP and SKILL��ָ�������ȵ�ɱ��(pker)
void copy_npc()
{
  object ob, *user;
  mapping skill_status,skl;
  string site;
  string *sname;
  string *skillname;
  int i, j, exp, lead_exp=0,skilllvl,m,n;
  int t=0,npc_num=0,copy_npc_time=1,npc_flag=0;

  user = users();
  j = sizeof(user);
  if (faction!="������")
  {
   for (i=0;i<j;i++)
   {
     if (!wizardp(user[i]) && user[i]->query("family/family_name")==faction)
          npc_num+=1;
    }
   if(npc_num<3) copy_npc_time=3;
   else copy_npc_time=2;
   npc_flag=0;
  }
  else
  { 
   if(j<40) copy_npc_time=5; 
   else     copy_npc_time=4;
   npc_num=j+1;
   npc_flag=1;
  }   
  if (npc_num==0)
   {
    message("channel:snow",HIM"��ҥ�ԡ�����"+faction+"���¿���һ�ˣ�������֯��ս��ʤ��һ��������"+faction+"��\n"NOR, users());
    message("channel:snow", HIC"�����ġ���ɱ��������ɱ�Ǵ�Ц����û�뵽������׵��֣�����������Ҳ����������������һ����\n"NOR, users());
    message("channel:snow",HIC"��"+HIM MUD_NAME+HIC"��������ʱ�����ˣ����ڽ������״̬��\n"NOR, users());
    LOGIN_D->set_madlock(0);
    remove_call_out("verdict_time");
    call_out("disaster",10,count+1);
    return;
   }   
   else
   {
   for (t=0;t<copy_npc_time;t++)
   { 
     for (i=0;i<j;i++)
       { 
        if (wizardp(user[i])) continue; // ��copy��ʦ
        if(faction!="������")
         {
           if(user[i]->query("family/family_name")==faction)
              npc_flag=1;
           else
              npc_flag=0;
         }
        if (npc_flag==1)
        {       
          exp = (int) user[i]->query("combat_exp");
          if (lead_exp < exp)
           {
          lead_exp=exp;
          lead = user[i];
           }
           if (exp < 50000)
             ob = new("/clone/haojie/pker1");
           else if (exp < 300000)
             ob = new("/clone/haojie/pker2");
           else if (exp < 600000)
             ob = new("/clone/haojie/pker3");
           else if (exp < 1500000)
             ob = new("/clone/haojie/pker4");
           else if (exp < 2500000)
             ob = new("/clone/haojie/pker5");
           else if (exp < 4000000)
             ob = new("/clone/haojie/pker6");
           else if (exp < 6000000)
             ob = new("/clone/haojie/pker7");
           else if (exp < 8000000)
             ob = new("/clone/haojie/pker8");
           else
             { 
              ob = new("/clone/haojie/pker9");
              ob->set("combat_exp",exp);
              }         
           skl = user[i]->query_skills();
           skilllvl=20; 
           if (sizeof(skl))
            {
              skillname = sort_array( keys(skl), (: strcmp :) );
              for (m=0; m<sizeof(skl); m++)
              {
                if (skilllvl < skl[skillname[m]])
                   skilllvl = skl[skillname[m]];
              }        
            }           
            skill_status = ob->query_skills();
            sname = keys(skill_status);

            for(n=0; n<sizeof(skill_status); n++)                   
               ob->set_skill(sname[n], skilllvl); 
                           
            site = query_site();
            ob->move(site);
            message_vision("$N�����ɷ�����˹�����\n",ob);
             }//npc_flag=1
            }//for all user    
          }//copytime
    remove_call_out("verdict_time");
    call_out("verdict_time",60);
   }
}

//���������������pker����ŵص�
string query_site()
{
  mapping sites=([
    "������": ({"/d/shaolin/smdian","/d/shaolin/guangchang2","/d/shaolin/fzlou","/d/shaolin/guangchang1"}),
    "�䵱��": ({"/d/wudang/sanqingdian","/d/wudang/guangchang","/d/wudang/xuanyuegate","/d/wudang/donglang2"}),
    "������": ({"/d/emei/huayanding","/d/emei/lianhuashi","/d/emei/ztpo1","/d/emei/xixiangchi"}),
    "��ɽ��": ({"/d/huashan/zhenyue","/d/huashan/yunu","/d/huashan/square","/d/huashan/buwei1"}),
    "ȫ���": ({"/d/quanzhen/damen","/d/quanzhen/datang2","/d/quanzhen/houtang1","/d/quanzhen/houtang3"}),
    "��ң��": ({"/d/xiaoyao/qingcaop","/d/xiaoyao/xiaodao1","/d/xiaoyao/xiaodao3","/d/xiaoyao/xiaodao4"}),
    "����": ({"/d/mingjiao/ziweitang","/d/mingjiao/square","/d/mingjiao/qiandian","/d/mingjiao/tianweitang"}),
//    "������": ({"/d/beijing/dongcha1","/d/beijing/dongcha2","/d/beijing/wangfu3","/d/beijing/xichang1","/d/beijing/xichang2"}),
    "������" : ({"/d/beijing/weifu_men","/d/beijing/kang1","/d/beijing/dongcha2","/d/beijing/xichang2","/d/beijing/wangfu2","/d/beijing/tian_anm","/d/beijing/xidan1","/d/beijing/di_anmen"}),
  ]);

  return sites[faction][random(sizeof(sites[faction]))];
}

void juedou()
{
  object ob;
  int i, exp, skill, killer = 0,topexp=5000000;

  ob = new("/clone/haojie/zhanshu.c");
  ob->move(lead);
  message_vision(HIY"һ��ս��Ʈ����$N����ǰ��\n"NOR,lead);
  message("channel:snow",HIM"��ҥ�ԡ�"+"��˵"+lead->name()+HIM"�õ���һ����ɱ��������ɱ�ǵ���ս�顣\n"NOR, users());
  exp = lead->query("combat_exp");
  skill = lead->query_skill("parry",1);
  ob = new("/clone/haojie/tianshaxing.c");
  ob->set("pk_target",lead);
  ob->set("combat_exp",(int)topexp);
  ob->move("/d/beijing/tian_anm.c");
  message_vision("$N�����ɷ�����˹�����\n",ob);
}

//ȡָ��pker������
int query_children(string arg)
{
  object *ch;
  int i,sum = 0;

  ch = children(arg);
  for(i=0;i<sizeof(ch);i++)
    if(environment(ch[i])) sum++;
  return sum;
}

//��ʱ�жϺƽٷ�����ʱ���Ƿ񳬹����ޣ������������ҳͷ�
void verdict_time()
{
  object *user,*ob_list;
  int i, exp, parry, force,sum=0;
  int limit,killer,topexp;
  if(faction!="������")
   limit=1800;
  else 
   limit=2400;

//���úƽٵ�����Ϊ30����(1800��)
  if( (time()-hj_startT) < limit )
  {
    sum += query_children("/clone/haojie/pker9.c");
    sum += query_children("/clone/haojie/pker8.c");
    sum += query_children("/clone/haojie/pker7.c");
    sum += query_children("/clone/haojie/pker6.c");
    sum += query_children("/clone/haojie/pker5.c");
    sum += query_children("/clone/haojie/pker4.c");
    sum += query_children("/clone/haojie/pker3.c");
    sum += query_children("/clone/haojie/pker2.c");
    sum += query_children("/clone/haojie/pker1.c");
    if (sum > 0) 
    {  
      remove_call_out("verdict_time");
      call_out("verdict_time",60);
     }
    else if (count+1 != sizeof(factions))
    {
      message("channel:snow", HIM"��ҥ�ԡ�"+faction+"������"+lead->name()+"�Ĵ����£�ɱ�õ��������ɾ�����ܶ��ӣ�\n"NOR, users());
      message("channel:snow", HIC"�����ġ���ɱ��������ɱ�ǣ������̵ģ�������Ӳ�����ȣ�\n"NOR, users());
      message("channel:snow", HIC"��"+HIM MUD_NAME +HIC"����ʱ���˵��ˣ��������Ƶõ����⣬��ʱ�������״̬��\n"NOR, users());
      LOGIN_D->set_madlock(0);
      remove_call_out("verdict_time");
      call_out("disaster",20,count+1);
    }
    else 
    {  
      user = users();
      for(i=0;i<sizeof(user);i++)
      { 
     	if (user[i]->query_temp("hj_killer") > killer) 
           {
          	lead = user[i];
          	killer=lead->query_temp("hj_killer");
           }
      if (user[i]->query("combat_exp")>topexp) 
          topexp= (int)user[i]->query("combat_exp");
      user[i]->delete_temp("hj_killer");
      }

      message("channel:snow", HIM"��ҥ�ԡ��������ɽӳ����ˣ���"+lead->name()+"�Ĵ����£����ڴ����������֯����ı�������ָֻ������յ�ƽ����\n"NOR, users());
      message("channel:snow",HIC"��"+HIM MUD_NAME+HIC"���з���ܣ������ָ�ƽ�����������״̬��\n"NOR, users());
      message("channel:snow", HIC"�����ġ���ɱ��������ɱ�������У��Ҳ��������Ҳ����������Ҳ�����������\n"NOR, users());
      LOGIN_D->set_madlock(0);
      remove_call_out("verdict_time");
//      call_out("verdict_time",60);
      call_out("juedou",2);
    }
  }
  else
  {
  if (!LOGIN_D->get_madlock()) return;
  ob_list = children("/clone/haojie/pker1");
  for(i=0; i<sizeof(ob_list); i++) 
    if(environment(ob_list[i]))
    {
      message_vision("$N˵���������������ǣ�����\n",ob_list[i]);
      destruct(ob_list[i]);
    }
  ob_list = children("/clone/haojie/pker2");
  for(i=0; i<sizeof(ob_list); i++) 
    if(environment(ob_list[i]))
    {
      message_vision("$N˵���������������ǣ�����\n",ob_list[i]);
      destruct(ob_list[i]);
     }     
  ob_list = children("/clone/haojie/pker3");
  for(i=0; i<sizeof(ob_list); i++) 
    if(environment(ob_list[i]))
    {
      message_vision("$N˵���������������ǣ�����\n",ob_list[i]);
      destruct(ob_list[i]);
    }
  ob_list = children("/clone/haojie/pker4");
  for(i=0; i<sizeof(ob_list); i++) 
    if(environment(ob_list[i]))
    {
      message_vision("$N˵���������������ǣ�����\n",ob_list[i]);
      destruct(ob_list[i]);
    }  
   ob_list = children("/clone/haojie/pker5");
   for(i=0; i<sizeof(ob_list); i++) 
    if(environment(ob_list[i]))
    {
      message_vision("$N˵���������������ǣ�����\n",ob_list[i]);
      destruct(ob_list[i]);
    }    
   ob_list = children("/clone/haojie/pker6");
   for(i=0; i<sizeof(ob_list); i++) 
    if(environment(ob_list[i]))
    {
      message_vision("$N˵���������������ǣ�����\n",ob_list[i]);
      destruct(ob_list[i]);
    } 
   ob_list = children("/clone/haojie/pker7");
   for(i=0; i<sizeof(ob_list); i++) 
    if(environment(ob_list[i]))
    {
      message_vision("$N˵���������������ǣ�����\n",ob_list[i]);
      destruct(ob_list[i]);
    }     
   ob_list = children("/clone/haojie/pker8");
   for(i=0; i<sizeof(ob_list); i++) 
    if(environment(ob_list[i]))
    {
      message_vision("$N˵���������������ǣ�����\n",ob_list[i]);
      destruct(ob_list[i]);
    }  
   ob_list = children("/clone/haojie/pker9");
   for(i=0; i<sizeof(ob_list); i++) 
    if(environment(ob_list[i]))
    {
      message_vision("$N˵���������������ǣ�����\n",ob_list[i]);
      destruct(ob_list[i]);
    }                            

  if (count+1 != sizeof(factions))
  {
    message("channel:snow",HIM"��ҥ�ԡ�"+faction+"������ս֮�£��������أ��Ӵ������伣��\n"NOR, users());
    message("channel:snow",HIC"�����ġ���ɱ��������ɱ�����һ������һ����\n"NOR, users());
    message("channel:snow",HIC"��"+HIM MUD_NAME+HIC"��������ʱ�����ˣ����ڽ������״̬��\n"NOR, users());
    LOGIN_D->set_madlock(0);
    call_out("disaster",10,count+1);
  }
  else
  {
    message("channel:snow", HIM"��ҥ�ԡ���Ȼ���ɷ���ɱ�У���������̫�󣬻��ǰ���������һʱ���ȷ�Ѫ�꣬����һƬ�찵��\n"NOR, users());
    message("channel:snow",HIC"��"+HIM MUD_NAME+HIC"����ɱ�Ŵ��ȫʤ������һƬ�ڰ������ڽ������״̬����ҿ�������!\n"NOR, users());
    LOGIN_D->set_madlock(0);
  }
 }
}

//���úͶ�ȡ�ƽٵĿ�ʼʱ��
void set_hj_startT(int i)
{
  hj_startT = i;
}
int query_hj_startT()
{
  return hj_startT;
}
