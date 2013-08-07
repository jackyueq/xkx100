// letter.c
// Last Modified by sir
// ����3��exp�������µ�������������,����exp ,pot����,�ָ�silver����

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"�ż�"NOR, ({ "letter","xin","secret letter" }));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long",
			"����һ���ż����ŷ�ĺ���ʵ����ڸ��ź���ӡ����\n");
		set("value", 0);
		set("material", "paper");
		set("no_drop",1);
		set("no_give",1);
		set("no_put",1);
	}
}
void init()
{	
	call_out("dest",random(200)+1200);
	add_action("do_send", "songxin");
	add_action("do_look", "kan");
	add_action("do_look", "chakan");
//	add_action("do_getxin", "get");
}
/*
int do_getxin(string arg)
{
	object me;
	me = this_player();
	
	if( (arg=="letter"||arg=="xin"||arg=="all")&&!me->query_temp("gb_songxin")) 
		return notify_fail("�㲻���ñ��˵Ķ�����\n");
}
*/
int do_look(string arg)
{
	int now_time, time;
	object me;

	me = this_player();
	now_time = me->query_condition("gb_songxin"); 
	time = me->query_temp("songxin_time");

	if(!arg) return 0;
	if( (arg=="letter"||arg=="xin")&&me->query_temp("gb_songxin"))
	{
		write("\n����һ����ؤ��Ŵ�����³�нŷ������ż�������д��"
			HIR" ��"+me->query_temp("songxin_target_name")+"�� ������\n"NOR);
		if(now_time > time*3/4) write("�������г����ʱ��ȥ���š�\n");
		if(now_time > time/2 && now_time <= time*3/4)
			write("�Ѿ���ȥһС��ʱ���ˡ�\n");
		if(now_time > time/4 && now_time <= time/2)
			write("�㻹��һ���ʱ��ȥ���š�\n");
		if(now_time > time/8 && now_time <= time/4)
			write("���ʱ���Ѿ������ˡ�\n");
		if(now_time > 0 && now_time <= time/8)
			write("ʱ�佫�������񼴽�ʧ�ܡ�\n");
	}
	else
	{
		if( (arg=="letter"||arg=="xin")&&!me->query_temp("gb_songxin")) 
			write("����һ���ܺ����ŷ�ĺ���ʵ����ڸ��ź���ӡ����\n");
	}
	return 1;
}

int do_send(string arg)
{
	int i,exp,pot,score,num,s_bonus,times,job_time,paytimes;
	object ob;
	object me,target,payment;
	string t_name;
	mapping fam;

        paytimes = 0;
	me=this_player();
	if(!arg) return notify_fail("��Ҫ�͸�˭��\n");
	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("������㣬��Ҫ���ŵ��˲������\n");
	t_name = target->query("name");
	job_time = me->query_temp("songxin_time");
	i = random((int)(target->query_skill("force",1)/5));

       	if(!target) return notify_fail("������㣬��Ҫ���ŵ��˲������\n");
	if(userp(target)) return notify_fail("�ٺ٣������ף���\n");
	if(me->query_temp("gb_songxin_late"))
		return notify_fail("�������Ѿ�ʧ���ˣ���������һ���ɡ�\n");
	if (!present("secret letter", this_player()) )
		return notify_fail("������û��Я���ż���\n"); 
/*
	if (!(fam = me->query("family")) || fam["family_name"] != "ؤ��")
		return notify_fail(RANK_D->query_respect(me) + "��ؤ��������������ô�����Ÿ��ң�");
*/
	if (!me->query_temp("gb_songxin"))
		return notify_fail(t_name+"��������ؤ�����Խ����㣬Ҫ���͵ģ����ǲ��Ǵӱ������������ģ�");
	if(me->query_temp("songxin_target_name") != t_name) 
		return notify_fail(t_name+"��������Ų��Ǹ��ҵģ����ǲ����ʹ��ˣ�");

	message_vision(HIY"$N����һ�Ѷ�ͷ�ĺ����ӻ����ͳ��Ž���$n˵��������ؤ��³�����������͸������ţ������պá�\n"NOR, me, target);
	message_vision("$N������$nһ���š�\n",me, target);
	message_vision(t_name+"���˵�ͷ˵������������,�������������°�! \n",me);
	target->add_money("silver",(int)(target->query_skill("force",1)/5)+1);
	command("give "+me->query("id")+" "+((int)(target->query_skill("force",1)/5)+1)+" silver");

	message_vision(HIY "$N�ӹ��ſ��˿������˵�ͷ˵������λ"+RANK_D->query_respect(me)+"�������ˡ�\n"NOR, target, me);
 

	if ((int)me->query("combat_exp")<=5000)
	{
		if (!me->query_temp("zuji"))
		{
			exp=((1+random(3))*50+(int)(job_time/5));
			pot=30+random(20);
		}
		else
		{
			exp=((1+random(3))*90+(int)(job_time/5));
			pot=50+random(20);
		}
	}
	if ((int)me->query("combat_exp")<=20000
		&&(int)me->query("combat_exp")>5000)
	{
		if (!me->query_temp("zuji"))
		{
			exp=(1+random(2))*70+(int)(job_time/6);
			pot=40+random(15);
		}
		else
		{
			exp=(1+random(2))*100+(int)(job_time/6);
			pot=60+random(30);
//			if (pot >150) pot=150;
		}
	}
	if ((int)me->query("combat_exp")>20000)
	{
		if (!me->query_temp("zuji"))
		{
			exp=(1+random(2))*60+(int)(job_time/8);
			pot=30+random(30);
		}
		else
         	{
			exp=(1+random(2))*80+(int)(job_time/16);
			pot=40+random(40);
//			if (pot >180) pot=180;
		}
	}

        
        num=(int)me->query("perform/number")+1;
        if (num<4) times=num;
         else times=4;
        
        if (!(fam = me->query("family")) || fam["family_name"] != "ؤ��")  score = 0;
         else score=random(10)+ 10 * times;
	
	s_bonus=50+random(50);
	
	me->add("potential",pot);
	me->add("combat_exp",exp);
	me->add("score",s_bonus);
        me->add("family/fealty",score);
	me->add("gb_job",1);
/*
        if (paytimes<i)       
        {
            payment=new("/clone/money/silver");
            payment->move(me);
            me->add("paytimes",1);
        }
*/
//      silver����

	tell_object(me,HIW"�ã��������,�㱻�����ˣ�\n" + 
		chinese_number(exp) + "��ʵս����\n" +
		chinese_number(pot) + "��Ǳ��\n"+
		chinese_number(score) + "���ҳ϶�\n"+
		chinese_number(s_bonus) + "�㽭������\n" +
		chinese_number(i)+"������\n"+
		"��Ϊؤ������"+me->query("gb_job")+"�ι�����\n"NOR);
		me->apply_condition("gb_songxin", me->query_condition("gb_songxin")/2);
		me->delete_temp("gb_songxin");
		me->delete_temp("songxin_time");
		me->delete_temp("songxin_target_name"); 
		me->delete_temp("songxin_where");
		me->delete_temp("letter_steal"); 
		me->delete_temp("zuji");
		me->set_temp("songxin_ok",1);
		me->delete_temp("songxin_zuji");
	      //me->clear_condition("gb_songxin");
		destruct(this_object());
		return 1;
}

void dest()
{
		destruct(this_object());
}
