 // Last Modified by Winder on Apr. 25 2001

#include <ansi.h>
inherit ITEM;
inherit F_QUEST;
#include "stuffs.h";

void create()
{
	set_name(WHT"����̵�"NOR, ({ "duandi", "di",}));
	set("weight", 100);
	seteuid(getuid());
	if(clonep()) set_default_object(__FILE__);
	else{
		set("unit", "ֻ");
		set("long", WHT"����Ѷ̵ó��棬ֻ�����ߴ�������ͨ���ף���Ө�ɰ���\n" NOR);
		set("value", 50); 
		set("no_get", 1);
		set("di_number", 0);
		set("no_drop", 1);
	}
	setup();
}

void init()
{
	add_action("mark_success", "sign");
	add_action("set_task", "blow");
	add_action("set_task", "chui");
	add_action("report_task", "report");
}

mapping get_stuffs()
{
	mapping quest = stuffs[random(sizeof(stuffs))];
	quest += (["time" : time()+quest["exp_reward"]*30,
		"last_id" : quest["id"],
		"type" : "��" ]);
        return quest;
}
int set_task(string arg)
{
	object where, me = this_player();  
	mapping quest;
	where = environment(me);

	if( !arg ) return 0;
	if( !this_object()->id(arg)) return 0;

	if( me->is_busy() || me->is_fighting()) 
		return notify_fail("����æ���ء�\n");    
	if(this_object()->query("xx_user") != getuid(me)) 
		return notify_fail("����ֻ���˵ĵ��Ӵ���\n");    
	if(!(where)->query("outdoors")) 
		return notify_fail("�������ﴵ���ӣ�������ô���ܴ���Զ�أ�\n");
	if(me->query_condition("gb_songxin") )
		return notify_fail("������������л��ӣ����ӵ����ؤ�������˵��\n");
	if(me->query_temp("xx/id")) 
		return notify_fail("����������ִ�������С�\n");  
	if(me->query_condition("job_busy")) 
		return notify_fail("���Ҫ�������ȵȵȰɡ�\n");           
	if(me->query_condition("wait_xx_task")) 
		return notify_fail("�ϴθ����ˣ������͵ȵȰɡ�\n");      
	tell_room(environment(me), HIY+me->name()+"����һֻ"+this_object()->query("name")+HIY"�ŵ��ڱߣ�����һ��������һ�ɳ���������������������ＤԽ��\n���������з�����������ȴʮ��������ȫ���ֵ���\n"NOR, ({ me }));
	tell_object(me,HIY"������"+this_object()->query("name")+HIY"�ŵ��ڱߣ����ᴵ��������\n"NOR);
	if((where)->query("outdoors") != "xingxiu" &&
		(where)->query("outdoors") != "xiyu")
		return notify_fail("�˵غ����޺�����̫Զ���Ÿ����������������\n"); 
	if(random(2)==1)
	{
		if(!mapp(quest = get_quest(me, 0, "ɱ"))) 
		quest = get_stuffs();
	}
	else quest = get_stuffs();
	me->set_temp("quest", quest);
	me->start_busy(1);          
	me->apply_condition("job_busy", 30);   
	remove_call_out("report");
	call_out("report", 1, me);
	return 1;
}
int report(object me)
{        
	if(!me) return 0;
  
	if( me->is_busy() || me->is_fighting()) 
		return notify_fail("����æ���ء�\n");   
	if (!me->query_temp("quest/id")) 
		return notify_fail("�����ڻ�û�н��յ��κ�����\n");
   
	message_vision(HIW"\nֻ������з���һֻ��ɫ�Ÿ룬����$N�ļ�ͷ��\n\n"NOR,me);
	message_vision("$N�����ŴӰ׸����Ͻ��£����һ�ۡ�\n",me);
	tell_object(me,"����д���� \n�����������˼��������Ҫ");
	if(me->query_temp("quest/type") == "ɱ")
		tell_object(me, "ɱ���� "+me->query_temp("quest/name")+"("+me->query_temp("quest/id")+") ����\n\n");
	else
		tell_object(me, "�õ��� "+me->query_temp("quest/name")+"("+me->query_temp("quest/id")+") ����\n\n");
	tell_object(me, "Ŀǰ�������ͨ���鿴����(report)���˽⡣\n");
	return 1;       
}
int report_task()
{
	int time;
	object me = this_player();
	time = me->query_temp("quest/time");
  
	if (!time) return notify_fail("�����ڻ�û�н��յ��κ�����\n");
	write("��Ŀǰ������Ŀ���ǣ�\n\n");
   
	if(me->query_temp("quest/type") == "ɱ")
		write("       ɱ���� "+me->query_temp("quest/name")+"("+me->query_temp("quest/id")+") ����\n\n����ʬ��������(sign corpse)���������ɵı�־��\n");
	else
		write("       �ҵ��� "+me->query_temp("quest/name")+"("+me->query_temp("quest/id")+") ������(xian)�����ɡ�\n\n");
   
	tell_object(me, "�������"+get_time(time)+"֮ǰ�������\n\n");
	return 1;
}
int mark_success(string arg)
{
	object target, me = this_player();
	string last;
  
	if(!arg) return notify_fail("��Ҫ��ʲô��\n");
	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("�Ҳ������������\n");
	if( me->is_busy() || me->is_fighting()) 
		return notify_fail("����æ���ء�\n");    
	switch (is_target(target, me))
	{
		case 0:  return 0;
		case -1: tell_object(me, "Ү��������ȥɱ������\n");
			return 0;
		case -2: tell_object(me,"��������ɱ�����ˣ�\n");
			return 0;
		case -3: tell_object(me,"���ˣ�ʱ���Ѿ����ˣ�\n");
			last = me->query_temp("quest/last_id");
			me->delete_temp("quest");
			me->set_temp("quest/last_id", last);
			me->apply_condition("wait_xx_task", 40); 
			return 0;
		case -4: tell_object(me,"Ŷ�����˺�NPCͬ����������ù��\n");
			return 0;
		default: break;
	}
	if(me->query("family/family_name") == "������")
	{
		message_vision(HIR"\n$N����һ������зɳ�һ��"BLU"��ӡӡ"HIR"�Ļ𻨣��������죬����$n�������ȼ��\n\n"NOR, me, target);
		target->set("name", HIB"�ս���ʬ��"NOR);
		target->set("long", HIB"һ�߱����ĵ��ս���ʬ�壬�������磬��״�ɲ���\n"NOR);
		me->add("xx_points", 1);
	}
	else
	{
		message_vision("$N����һ������ī����$n��������д���ˡ����ޡ����֡�\n", me, target);
		target->set("long", target->query("long")+"\n��������д�˴��� "HIB"����"NOR" ���֡�\n");
	}
	call_out("done", 1, me);   
	me->start_busy(1);    
	return 1;
}      
void done(object me)
{
	int num,times,score;
	mapping quest,fam;
	if(!me) return;
	quest = me->query_temp("quest");
        
        num=(int)me->query("perform/number")+1;
        if (num<4) times=num;
         else times=4;
        
        if (!(fam = me->query("family")) || fam["family_name"] != "������")  score = 0;
         else score=random(10)+ 10 * times;        
	
	me->add("combat_exp", quest["exp_reward"]);
	me->add("potential", quest["pot_reward"]);
	me->add("family/fealty",score);
	
	tell_object(me, "�ã�������ɣ�����������һ��ɸ봫���ͻ����޺���\n");
	tell_object(me, GRN"����"+chinese_number(quest["exp_reward"])+"�㾭���"+chinese_number(quest["pot_reward"])+"��Ǳ�ܺ�"+chinese_number(score)+"���ҳ϶ȵĽ�����\n"NOR);

	
	me->add("shen", -(quest["exp_reward"]*15));
	me->delete_temp("quest");
	me->set_temp("last_id", quest["last_id"]);
//	me->apply_condition("job_busy", 3);  
	me->clear_condition("job_busy");
	return;
}

