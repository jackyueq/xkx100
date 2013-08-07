// /clone/misc/chutou.c
// Last modified by winder 2003.9.2

inherit ITEM;
#include <ansi.h>;
int do_wajue();

void create()
{
	set_name(HIG"��ͷ"NOR, ({ "chu tou", "bao chu", "chu" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѷ��ź���ӫ������ƾ��ֳ�ͷ���������������ھ�(wajue)ʲô������\n");
		set("wajue", 0);
//		set("no_sell",1);
//		set("no_drop",1);
/*		set("no_put",1);
		set("no_get",1);
		set("no_beg",1);
		set("no_steal",1);	
*/		set("value", 1000000);
		set("no_value",1); // dropʱ��ʧ
		set("material", "steel");
		 
	}
	
	setup();
}

void init()
{
        add_action("do_wajue", "wajue");
}

int do_wajue()
{
	int t, time;
	string *dir, target;
	object ob, me = this_player(), where = environment(me),obj;
//	return 1;
	t = time()-where->query_temp("wajue");
	time = where->query_temp("wajue1");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�\n");
	if (!present("bao chu", me))
		return notify_fail("��û�г�ͷ����ô�ھ�ѽ����\n");
	
		
	if (!wizardp(me))
	{
		obj = present("chu tou", me);
		if ((int)me->query("jing") < 50)
			return notify_fail("�����˰��죬���������ˣ�\n");
		if (!environment(me)->query("outdoors"))
			return notify_fail("�ڷ�������Ҳ���ڱ�����\n");
		if (present("bao wu",me))
			return notify_fail("�������Ѿ��б����ˣ���̫̰�ģ�\n");
		if (me->query_temp("baowunum") >= 1)
		        return notify_fail("Τ��ү�������Ĵ�Ѱ���أ�������ȥ��\n");
		if( t <= time && !(me->query_temp("invite") && random(2)==1))
			return notify_fail("�����ѱ����ڹ���һ��������ɣ�\n");
		if (me->is_fighting()) 
			return notify_fail("����������𾢣����п����أ���\n");
	}
	if (random(10) <= 6 )
	{
		printf(HIC"���ó�һ�ѳ�ͷ���ڵ������˰��죬ʲôҲû���ڵ���\n"NOR);
		t = (300 + random(10) );
		where->set_temp("wajue", time());    
		where->set_temp("wajue1", t);                
    if (random(30) <= 2)
    if (me->query_temp("invite")) me->start_busy(2); 
    else  me->start_busy(1);
		return 1;
	}
	else
	{ 
		printf( HIC"���ó�һ�ѳ�ͷ���ڵ������˰��죬ͻȻ����ú����ڵ���ʲô��\n"NOR);   
		switch (random(10))
		{
			case 0:
			case 1:
			case 2:
				ob = new(__DIR__"baowu");
				ob->set("owner",me->query("id"));
				ob->move(me);
				tell_object(me, HIW"���������ڵ��ھ��㷢����һ�����\n"NOR);
				tell_object(me, HIW"��ϲ������\n"NOR);				
				me->add_temp("baowunum",1);
				break;
			case 3:
				dir = get_dir("/clone/food/fruit/");
				ob = new("/clone/food/fruit/"+dir[random(sizeof(dir))]);
//				ob->set("owner",me->query("id"));
				ob->move(me);
				tell_object(me, HIW"���������ڵ��ھ��㷢����һЩ������\n"NOR);
				break;
			case 4:
			case 5:
				dir = get_dir("/clone/medicine/vegetable/");
				ob = new("/clone/medicine/vegetable/"+dir[random(sizeof(dir))]);
				if(ob->query("id")=="lingzhi"||ob->query("id")=="fuxin cao"||ob->query("id")=="xuelian")
				{
				message_vision("�ۣ�$N�ڵ���һ��é�ӡ�\n", me);
				tell_object(me,"��ô�����é�Ӷ����ڳ���������������\n");
				break;
				}
//				ob->set("owner",me->query("id"));
				ob->move(me);
				tell_object(me, HIW"���������ڵ��ھ��㷢����һЩҩ�ġ�\n"NOR);
				break;
			case 6:
/*
				message_vision("��ѽ���ã�$N�ڵ������ˣ�һ�����ߴӶ������˳�����\n", me);
				tell_object(me,"�������ܣ�\n");
				ob = new("/clone/animal/snake");
				ob->move(environment(me));
				break;
*/
			case 7:
/*
				message_vision("һ��ͷ��ȥ��$N�ڳ�һ�����ӡ�\n", me);
				ob = new("/clone/animal/yetu");
				ob->move(environment(me));
				break;
*/
			case 8:
				message_vision("�ۣ�$N�ڵ���һ��é�ӡ�\n", me);
				tell_object(me,"��ô�����é�Ӷ����ڳ���������������\n");
				break;
			default:
				message_vision("�ۣ�$N�ڳ���һ�ھ���\n", me);
				tell_object(me,"��ϧ�ڵĵط����ԣ��⾮����ð�̣�ʲôҲ���ᡣ\n");
		}
		
		t = ( 30 + random(10) ) * 100;
		where->set_temp("wajue", time());    
		where->set_temp("wajue1", t);	  
		me->receive_damage("jing", 20);
		return 1;
	}
}

