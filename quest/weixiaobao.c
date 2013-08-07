// /quest/wei.c
// Modified by Zeratul Jan 5 2001
// Modified by Sir 5/17/2001 
// 10������һ��,�����ۼ�,������������֮���ʱ�����ƣ��ָ���Ǯȡ���Ĺ���
// 500��һ�֣������������������
inherit NPC;
inherit F_SKILL;
#include <ansi.h>;
#include <quest.h>
#define GIFT_DIR "/clone/gift/"

void special_bonus(object me, object who,string type);
string time_period(int timep,object me);
int do_answer(string arg);
int do_cancel();
int do_fangqi();
string do_gonglao();
#define MAX_BAOWU_EXP 10000000
#define MAX_NEED 1000000  //100goldȡ��
int is_manager() {return 1;}

void create()
{
  set_name("ΤС��", ({ "wei xiaobao", "wei", "xiaobao" }));
  set("title", HIC"�������Զ�󽫾�"HIY"һ��¹����"NOR);
  set("nickname", HIW"С����"NOR);
  set("gender", "����");
  set("age", 18);
  set("str", 20);
  set("int", 30);
  set("con", 30);
  set("dex", 20);
  set("per", 28);
  set("long", 
"��λ���꽫��ͷ���춥�ӣ�������ӣ�ü����Ц����߯��
�⣬������ҡ���ȣ��������֮�������ֵ��ϴ󵶣�ٲȻ��
��֮��������Τ��С����Ҳ�����㿴��������������������
���Ц������ѧ����Ϸ���вܲٵ�ģ�������ʱ�̲�ס�ո�
Ȥ����һ�䣺������Ϊ�η�Ц����\n");
  set("combat_exp", 50000);
  set("shen_type", 1);
  set("attitude", "peaceful");
  set("max_qi", 2500);
  set("max_jing", 1000);
  set("neili", 500);
  set("max_neili", 500);
  set("jiali", 50);

  set_skill("force", 20);
  set_skill("parry", 20);
  set_skill("hand", 20);
  set_skill("dodge", 20);
  set_skill("shenxing-baibian", 20);
  set_skill("yunlong-shengong", 20);
  set_skill("qianye-shou", 90);

  map_skill("force", "yunlong-shengong");
  map_skill("parry", "qianye-shou");
  map_skill("dodge", "shenxing-baibian");
  map_skill("hand", "qianye-shou");
  prepare_skill("hand", "qianye-shou");
  set("inquiry", ([
      "��ػ�" : "���ң�\n",
      "�½���" : "������ʦ����\n",
      "éʮ��" : "������ʮ�˸�ë�氡������û���ɣ�\n",
      "��������": "��������ò���ʦ����\n",
      "Τ����" : "�������������Խ��Խ���ˣ����ڸ���������ˣ�\n",
      "����"   : "�����һʵ�ʦ����\n",
      "С����" : "�����һʵ�ʦ����\n",
      "С����" : "������������ˣ������£�\n",
      "����"   : "��������ý��Ȣ�Ĵ����ţ�\n",
      "˫��"   : "����ʶ�����󹦸�ɣ��׸������\n",
      "����"   : "������������ô�������Ϻ鸣���죬���޸����죡\n",
      "����"   : "������������ô�������Ϻ鸣���죬���޸����죡\n",
      "����"   : "������������ô�������Ϻ鸣���죬���޸����죡\n",
      "�彣��" : "������������ô�������Ϻ鸣���죬���޸����죡\n",
      "��������" : "���ɧ��Ƥ���׺񲻼�˫������ò�������桢�书�������������ɲ������������洿�Ʋ����彣��������˹�Ĳ������ᣬ����һ��֮���ߣ����������������ѣ�\n",
      "ȡ������":  (: do_cancel :),
      "cancel" :   (: do_cancel :),
      "����"   :   (: do_gonglao :),
      "gonglao":   (: do_gonglao :),
//      "����"��  (:do_fangqi:),
//      "fangqi": (:do_fangqi:),
  ]) );

  setup();
  carry_object(CLOTH_DIR"jinduan")->wear();
}

void init()
{
  object ob;

  ::init();
  add_action("give_quest", "quest");
}
int do_cancel()
{ 
  object who=this_player();
  if (who->query("quest/wei/finished")==1)
  {
    tell_object(who,"ΤС��Ц������û�������񰡣���ʲô��ȡ���ġ�\n");
    return 1;
  }
  if (who->query("balance")<1000000)
  {
    tell_object(who,"ΤС��Ц����������΢���Ҳ������Ǻú���һ����Ҫ�Ķ����ɡ�\n");
    return 1;
  }
  who->add("balance",-1000000); 
  tell_object(who,"ΤС��Ц�����úã��Ҿ�����һЩ�ƽ���Ϊ��������Ҳ�����������ˣ���ȥ��Ϣ��Ϣ�ɡ�\n");
  who->set("quest/wei/finished",1);
  who->delete( "quest/wei/time" );
  return 1;
}
string do_gonglao()
{
  if (this_player()->query("quest_num/wei"))
  return "���Ѿ����������ռ���"+chinese_number(this_player()->query("quest_num/wei"))+"�������ˡ�";
  else
  return "��û�а�������ʲô���鰡��";
}

int do_fangqi()
{
  object who=this_player();
  return 0; 
}
//int do_answer(object ob,object me,string arg)
int accept_reply(object me,object ob,string arg)
{
  object obj;
  string un;
  int meili,gift,ans;
  string type;
  string need;
  int mysc;
  
  if (!me->query_temp("quest_gift/got")||!stringp(type = me->query_temp("quest_gift/type")))   return 0;
  if (arg=="Y" || arg=="y" || arg=="yes")  ans=1;
  else if (arg=="N" || arg=="n" || arg=="no") ans=2;
  else return 0;
  if (living(me) && living(ob) && ans==1)
  {
		me->delete_temp("quest_gift/got");
		type = me->query_temp("quest_gift/type");
		if (type == "meili") 
		{
			need = "��������";
			mysc = me->query("meili");
		}
		else if (type == "gongxian") 
		{
			need = "���ɹ���";
			mysc = me->query("family/gongxian");
		}
		if ( mysc < me->query_temp("quest_gift/need") )
			return notify_fail("�����ô��"+need+"��Ҳ����˼��"+ob->name()+"Ҫ������\n");
      message_vision(CYN "\n$N" CYN "��æ���ͷ��˵�����ⶫ��������Ҳ��Ҫ���ͽ����Ұɡ�\n" NOR, me);
      arg=me->query_temp("quest_gift/obj");
      obj = new(arg);
      if (!objectp(obj))
        return notify_fail(ob->name()+"���Ƶ����ף��ҵĶ����أ��ղŻ��ڣ���ôת�۾�û�ˡ�\n");
      if (obj->query("base_unit"))
         un = obj->query("base_unit");
      else
         un = obj->query("unit");
      if (type == "gongxian")
      	me->add( "family/gongxian", - me->query_temp("quest_gift/need"));
      else 
      	me->add(type, - me->query_temp("quest_gift/need"));
      message_vision("$N΢΢һЦ���ó�һ" + un + obj->name() + NOR "����$n��\n" NOR,ob,me);
      obj->move(me);
      log_file("gift/wei_give",sprintf("[%s]%8s give %8s %20s \n",ctime(time()),ob->query("id"),me->query("id"),base_name(obj)));
      return 1;
    }
    else if (living(me) && living(ob) && ans==2)
      {
        me->delete_temp("quest_gift/got");
        tell_object(me,HIW+ob->name()+"̾������Ҳ�գ���Ȼ�㲻��Ҫ���ⶫ����"
                                       "���������˰ɡ�\n"NOR);
        return 1;
      }
      return 0;
}

int give_quest()
{
  mapping quest;
  object me = this_player();
  int combatexp, timep, factor;
  int num;

  combatexp = (int) (me->query("combat_exp"));
  if(combatexp<1000)
  {
    tell_object(me,"ΤС���������һ���������������裬������û����������\n");
    return 1;
  }
/*  if(combatexp>10000000)
  {
    tell_object(me,"ΤС���������һ���������������裬�����ү��æ���أ�û�����㣡��\n");
    return 1;
  }
*/  if (me->query("meili") < 0 || me->query("weiwang") < 0)
  {
    tell_object(me,"ΤС���������һ�����������Ǹ�ʲô������Ҳ�����ﵷ�ҡ�\n");
    return 1;
  }
  if (me->query("combat_exp") <= me->query("quest/wei/busy_exp"))
  {
    tell_object(me,"ΤС������˵��������ʱ����Ҫ���æ������ȥ�����ط�����һ��������\n");
    return 1;
  }
  if (me->query_temp("quest_gift/got"))
  {
     tell_object(me,"ΤС������˵�����������㻰�أ�����ش�(answer y|n)����\n");
      return 1;
    }
// Let's see if this player still carries an un-expired task
  if( me->query("quest/wei/quest") && !me->query( "quest/wei/finished" ) )
  {
    if( ((int) me->query("quest/wei/time")) > time() )
    {
      tell_object(me,"ΤС������Ц����˵�㲻�аɣ�����������\n");
      return 1;
    }
    else
    {
      tell_object(me,"ΤС��������̾��һ������û��ϵȥ�ñ��Ҳ�ɡ�\n");
//      me->add("qi",-(int)(me->query("qi")/5));
//      quest_failed( me, "wei" );

//      tell_object(me,HIW"ΤС������˵������������ȥ�á�"+me->query("quest/wei/quest")+HIW+"����ʱ���Ѿ����ˣ���Ҫ�Ķ����ء�\n"NOR);
//      return 1;
    }
  }
  else
//    if ( me->query("/quest/wei/time") + 90 + random(60) > time())   
      if ( me->query("/quest/wei/time") + 2 > time())   
    {
      tell_object(me,"ΤС������΢΢һЦ������������ۣ�ЪϢ�������·�ɡ�\n");
      return 1;
    }

//  factor=10;
    if(!me->query("quest_num/wei") || 
    (int)me->query("quest_num/wei")<0 ||
    (int)me->query("quest_num/wei")>500)
      me->set("quest_num/wei",1); //�������quest_num/wei������

  num=me->query("quest_num/wei");
  if(num <= 5)
    quest = __DIR__"qwlist1"->query_quest("easy_quest");
  else if ( num%50 == 0)
  {
    quest = __DIR__"qwlist1"->query_quest("hard_quest");
    tell_object(me,"ΤС��΢΢һЦ�����ò���������ҿ����и������һЩ������\n");
  } 
  else
    quest = __DIR__"qwlist1"->query_quest("normal_quest");
  timep = random(10) * 60 + 15*60;
  
  tell_object(me,HIW "ΤС���Ը�����������" + time_period(timep, me) + "��");
  tell_object(me,"�ҵ���"+quest["quest"]+HIW"�����ң��һ�ú�л�㡣\n" NOR);

  quest["quest_type"] = "Ѱ";
//  quest["exp_bonus"] = 10 + random(10);
//  quest["pot_bonus"] = 2 + random(4);
//  quest["score"] = 2 + random(4);

  me->set("quest/wei/quest", quest["quest"]);
  me->set("quest/wei/time", (int)time()+timep);
//  me->set("quest/wei/factor",factor);
  me->set( "quest/wei/finished",0 );
  me->set("quest/wei/quest_type",quest["quest_type"]);
  me->delete("quest/wei/busy_exp");
//  if(!me->query_temp("wei_quest_num") ||
//    (int)me->query_temp("wei_quest_num")==10)
//    me->set_temp("wei_quest_num",1);
//  if ((int)me->query_temp("wei_quest_num")<0) 
//    me->set_temp("wei_quest_num",1);
//add by sega 4/11/2000
//  me->set("last_quest_time",(int)time());
//  me->add("quests/require", 1);
  return 1;
}

string time_period(int timep, object me)
{
  int t, d, h, m, s;
  string time;
  t = timep;
  s = t % 60; t /= 60;
  m = t % 60; t /= 60;
  h = t % 24; t /= 24;
  d = t;

  if(d) time = chinese_number(d) + "��";
  else time = "";

  if(h) time += chinese_number(h) + "Сʱ";
  if(m) time += chinese_number(m) + "��";
  time += chinese_number(s) + "��";

  return time;
}

int accept_object(object who, object ob)
{
  int exp, pot, score, num,level, myexp;
  mapping quest;
  object gift;
  int need;

  if (ob->query("id") == "bao wu")
  {
    if (who->query_temp("baowunum") < 0)    
            return notify_fail("ȥȥȥ���Ķ��ҵļٻ���������Τ��ү�ң���\n");               
    if (ob->query("owner") != who->query("id") )
    {
      tell_object(who,HIW"ΤС�����˵�˵��������Ҫ" + ob->query("name")+ HIW"�أ���л��ѱ��˵ı���ת�͸��ҡ�\n"NOR);
    }
    else
    {
      exp = 10 + random(10);
      pot = 7 + random(5);
      score= 5 + random(10);
      who->add("score",score);
      who->add_temp("baowunum",-1);
      who->add("marks/baowu",1);
      tell_object(who,HIW"ΤС�����˵�˵��������Ҫ" + ob->query("name")+ HIW"�أ������������Ҳ����Щ�����ɡ�\n");
     if ((who->query("combat_exp") < MAX_BAOWU_EXP)  || who->query_temp("invite"))
      {
        who->add("combat_exp",exp);
        who->add("potential", pot);
        tell_object(who,"��"+ chinese_number(exp) + "�㾭�飬" + chinese_number(pot) + "��Ǳ�ܣ�"+ chinese_number(score) + "�㽭��������)\n"NOR);
		  }
		  else 
		  {
		  	exp = exp/2;
		  	pot = 1;
        who->add("combat_exp",exp);
        who->add("potential", pot);
        tell_object(who,"��"+ chinese_number(exp) + "�㾭�飬" + chinese_number(pot) + "��Ǳ�ܣ�"+ chinese_number(score) + "�㽭��������)\n"NOR);
    	}
    }
    return 1;
  }
  if ( ob->query("money_id") )
  {
  	need = 10000;
  	myexp = who->query("combat_exp");
  	if (myexp <= 100000 ) need = 1000; // 10 silver 
  	else if (100000 <= myexp && myexp <= 500000) need = 3000; // 30 silver
  	else if (500000 <= myexp && myexp <= 1000000) need = 5000; // 50 gold
  	else if (100000 <= myexp && myexp <= 2000000) need = 10000; // 1 gold
  	else if (200000 <= myexp && myexp <= 3000000) need = 20000; // 2 gold
  	else if (300000 <= myexp && myexp <= 4000000) need = 30000; // 3 gold
  	else if (400000 <= myexp && myexp <= 5000000) need = 40000; // 4 gold
  	else need = 50000; // 5 gold
    if ( !who->query("quest/wei/quest") ||
      who->query("quest/wei/finished") ||
      ob->value() < need )
      tell_object(who,"ΤС��Ц�������ҿɾͲ������ˡ�\n");
    else if (ob->value()>=MAX_NEED)
    {
      who->set("quest/wei/finished",1);
      tell_object(who,"ΤС��Ц�����úã�������ô�г��⡣��Ҳ�����������ˣ���ȥ��Ϣ��Ϣ�ɡ�\n");
      who->delete( "quest/wei/time" );
      }
    else
    {
      tell_object(who, "ΤС��̾�˿���˵�����Ǻã������������������ڡ���Ҫ�ô������Ұɣ�\n");
      if(random(20)==1 && who->query("combat_exp") > 150000) 
        {
        tell_object(who,HIR"�����㾭���겻������ΤС����ʼ���������ˡ�\n"NOR);
        who->add("weiwang",-10);
        who->set("quest/wei/busy_exp",who->query("combat_exp")+300);
        if (who->query("meili")>100)
        who->add("meili",(int)-query("meili")/3);
        else
        who->add("meili",-25);
        }
      who->set( "quest/wei/finished", 1 );
      who->set( "quest/wei/time" ,time()+10);
      who->delete("quest_num/wei");
    }
    return 1;
  }
  
  if (  (!quest = who->query( "quest/wei/quest" ))  ||
    who->query( "quest/wei/finished" ) )
  {
    tell_object( who,"ΤС��˵���������������\n" );
    return 0;
  }
  if( ob->query("name") != quest || ob->is_character() )
  {
    tell_object(who, "ΤС��˵��������ʲô�������ҽ����������������Ū�ң���\n");
    return 0;
  }
  if ((int) who->query("quest/wei/time") <= time() )
  {
    tell_object(who,"ΤС��˵����������ô��ã����ڲŰѶ���Ū������ξ����ˣ��Ժ�Ҫע�⡣\n");
//    quest_failed( who, "wei" );
    who->delete("quest/wei/quest");
//    who->delete("quest_num/wei");
//    quest_finished( who, "wei" );
    who->delete("quest/wei/finished");
//    who->delete("")
//    destruct(ob);
    ob->set("id","bao wu");//��give.c����Ʒdest
    return 1;
  }
  else
  {
    tell_object(who,"ΤС������ص�ͷ˵����������ʹ��ò���\n");
    who->set("quest/wei/finished",1);

    num = (int)who->query("quest_num/wei");
    if (num >= 450) level=9;
    else if (num >= 400) level=8;
    else if (num >= 200) level=7;
    else if (num >= 100) level=6;
    else if (num >= 50) level=5;    
    else if (num >= 20) level=4;
    else if (num >= 6) level=3;
    else level=0;
    if (who->query("combat_exp")<200000 && level<1) level=1;
    if (level>=10) level=10;
    exp = 60* level + random(30)+3;
    exp=exp*2/3+random(exp*2/3);
    pot = 18* level + random(9)+1; 
    pot=pot*2/3+random(pot*2/3);
    score = 20 + 20* level + random(10);
    who->add("combat_exp", exp);
    who->add("potential", pot);
    who->add("score", score);
	who->set_temp("prize_reason","С��");
	who->set_temp("can_give_prize",1);
	who->set_temp("prize_exp",exp);
	who->set_temp("prize_pot",pot);
    tell_object(who,HIW"����һ�����౼�����������ˣ�" + chinese_number(exp) + "��ʵս���飬"+ chinese_number(pot) + "��Ǳ�ܣ�" + chinese_number(score)+"�㽭��������\n"NOR);
    tell_object(who,HIW"��ϲ����ɵ�"+chinese_number(who->query("quest_num/wei"))+"����ʹ��\n"NOR);   

    who->delete("quest/wei/busy_exp");
    if (num>49 && num<501 && num%50==0 ) 
      special_bonus(this_object(),who,"meili");  //����ʮ��������Ʒ����

    who->add("quest_num/wei",1);
    who->add("quest_num/allwei",1);
    
    if (who->query("skybook/luding/passed")) who->add("meili",2);
    //�����ʮ���¾����� ����������һЩ
    else who->add("meili",1);
    
    who->set("quest/wei/time", (int)time());
    if (num>30 && random(100)==1)
    {
    who->set("quest/wei/busy_exp",who->query("combat_exp")+1000);
    gift=new("/clone/money/gold");
    gift->set_amount(50);
    message_vision("$NЦ������λ"+RANK_D->query_respect(who)+"ʵ�����ҵĵ������֣�������Щ�ƽ��������š���ȥ�ú�ЪϢЪϢ�����ۻ������ӡ�\n" NOR,this_object()); 
    gift->move(this_object());
    command("give 50 gold to "+who->query("id"));
    }
    destruct(ob);
    return 1;
  }
  return 1;
}

//��Ʒ����
void special_bonus(object me, object who,string type)
{
        int cost;
        string need;
        int mysc;

        // ��ʮ����
        string *ob1_list = ({//�鱦
                "clone/jewelry/biyu",
                "clone/jewelry/feicui",
                "clone/jewelry/goldring",
                "clone/jewelry/maoeryan",
                "clone/jewelry/necklace",
                "clone/jewelry/shanhu",
                "clone/jewelry/yubei",
                "clone/jewelry/yudai",
        });

        // ���һ�ٸ�����
        string *ob2_list = ({//��ҩ
          "/clone/medicine/nostrum/baihudan",
          "/clone/medicine/nostrum/baiyunwan",
          "/clone/medicine/nostrum/huiyangsan",
          "/clone/medicine/nostrum/jiuhuawan",
          "/clone/medicine/nostrum/shenyangjiu",
          "/clone/medicine/nostrum/tianxianggao",
        });

        // ���һ����ʮ������
        string *ob3_list = ({//����������ҩ
           "/clone/medicine/nostrum/xiongdan",
           "/clone/medicine/nostrum/guaishedan",
           "/clone/medicine/nostrum/guaishexue",
           "/clone/medicine/nostrum/huochan",
          GIFT_DIR+"gift/con1",
          GIFT_DIR+"gift/str1",
   //       GIFT_DIR+"gift/int1",
          GIFT_DIR+"gift/dex1",
        });

        // ��ɶ��ٸ�����
        string *ob4_list = ({//�ͼ��书ҩ
          GIFT_DIR+"pill/renshen1",
          GIFT_DIR+"pill/lingzhi1",
          GIFT_DIR+"pill/xuelian1",
          GIFT_DIR+"pill/shouwu1",
        });

        // ��ɶ�����ʮ������
        string *ob5_list = ({//�߼�������ҩ
           "/clone/medicine/nostrum/labazhou",
           "/clone/medicine/nostrum/renshenguo", 
           "/clone/medicine/nostrum/binghuojiu",
        });

        // ������ٸ�����
        string *ob6_list = ({//�м��书ҩ
           "/clone/medicine/nostrum/puti-zi",
          GIFT_DIR+"pill/renshen2",
          GIFT_DIR+"pill/lingzhi2",
          GIFT_DIR+"pill/xuelian2",
          GIFT_DIR+"pill/shouwu2",
        });

        // ���������ʮ������
        string *ob7_list = ({//�м��츳ҩ
          GIFT_DIR+"gift/con2",
          GIFT_DIR+"gift/str2",
     //     GIFT_DIR+"gift/int2",
          GIFT_DIR+"gift/dex2",
        });

        // ����İٸ�����
        string *ob8_list = ({//�߼��书ҩ
          GIFT_DIR+"pill/renshen3",
          GIFT_DIR+"pill/lingzhi3",
          GIFT_DIR+"pill/xuelian3",
          GIFT_DIR+"pill/shouwu3",
        });

        // ����İ���ʮ������
        string *ob9_list = ({//�Ӹ�Ե�������Եȵĵ�ҩ
          GIFT_DIR+"gift/kar",
          GIFT_DIR+"gift/spi",
          GIFT_DIR+"gift/sta",
          GIFT_DIR+"gift/per",
          GIFT_DIR+"gift/cps",
          GIFT_DIR+"gift/cor",
        });

        // �����ٸ�����
        string *ob10_list = ({//�ӱ������������Եĵ�ҩ
          GIFT_DIR+"gift/str3",
          GIFT_DIR+"gift/con3",
          GIFT_DIR+"gift/dex3",
       //   GIFT_DIR+"gift/int3",
        });


        string un, gift;
        object ob;
        int count;

        if (type == "meili") 
        	count = who->query("quest_num/wei");
        else if (type == "gongxian")
       		count = who->query("quest_num/kill")/2;
       	else count = 0;


        if (count == 500)
        {
                gift = ob10_list[random(sizeof(ob10_list))];
                cost = 200;
        } else

        if (count == 450)
        {
                gift = ob9_list[random(sizeof(ob9_list))];
                cost = 200;
        } else

        if (count == 400)
        {
                gift = ob8_list[random(sizeof(ob8_list))];
                cost = 150;
        } else

        if (count == 350)
        {
                gift = ob7_list[random(sizeof(ob7_list))];
                cost = 150;
        } else

        if (count == 300)
        {
                gift = ob6_list[random(sizeof(ob6_list))];
                cost = 100;
        } else

        if (count == 250)
        {
                gift = ob5_list[random(sizeof(ob5_list))];
                cost = 100;
        } else

        if (count == 200)
        {
                gift = ob4_list[random(sizeof(ob4_list))];
                cost = 70;
        } else

        if (count == 150)
        {
                gift = ob3_list[random(sizeof(ob3_list))];
                cost = 40;
        } else

        if (count == 100)
        {
                gift = ob2_list[random(sizeof(ob2_list))];
                cost = 10;
        } else

        if (count == 50)
        {
                gift = ob1_list[random(sizeof(ob1_list))];
                cost = 5;
        } 
        else
        {
                return;
        }
        ob = new(gift);

        if (ob->query("base_unit"))
                un = ob->query("base_unit");
        else
                un = ob->query("unit");
        
        if (type == "gongxian") mysc = who->query("family/gongxian");
        else mysc = who->query(type);
        if (mysc >= cost)
        {
                message_vision(CYN "$n" CYN "��$N" CYN "΢Ц����������ոյõ�һ"
                               + un + ob->name() + CYN "����Ҫ�Ļ�������Ҳ�޷���\n" NOR, who, me);

                if (type == "meili") need = "��������";
                else if (type = "gongxian") need = "���ɹ���";
                tell_object(who, HIW "\n���" + ob->name() + HIW "�ή��"
                                 "��" + chinese_number(cost) + "��"+need+
                                 "�������ѡ��ش�(reply Y|N)�ǻ��߷�\n" NOR);

                // ��¼������ȡ����
                who->set_temp("quest_gift/got", 1);

                // ��¼��������Ʒ��·��
                who->set_temp("quest_gift/obj", gift);

                // ��¼��ȡ����Ʒ��������ƹ���
                who->set_temp("quest_gift/need", cost);
                
                who->set_temp("quest_gift/type", type);
        } 
        else 
        {                
        	message_vision(CYN "$n" CYN "��$N" CYN "΢Ц�����Ҹո��õ�����"+
                       "�ţ����ˣ�������Ҳ�ò��š�\n" NOR, who, me);
        }
        destruct(ob);
}