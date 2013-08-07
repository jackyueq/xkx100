// /d/city/obj/bing6.c ״Ԫ��

inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIY "��ת��" NOR, ({ "jiuzhuan jindan", "dan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", "һ�Ž�ɫ���ɵ�����˵��̫���Ͼ������������鵤��ҩ��\n");
		set("no_get", 1);
		set("no_drop", 1);
		set("no_put", 1);
		set("no_beg", 1);
		set("no_steal", 1);
	}
	setup();
}

int do_eat(string arg)
{
	int i;
	object me=this_player();
	object ob=this_object();
	int effect = 0;
	
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
		message_vision(HIY "$Nһ����������һ"+ob->query("unit")+"$n��\n" NOR, me,ob);

// ����
	if (me->query("gift/str/all") < 10 && me->query("str") < 35 && random(2))
	{
		effect++;
//		write(HIG "������Լ���������ǿ���ˡ�\n" NOR);
		write(HIG "������������ˡ�\n" NOR);
		me->add("gift/str/succeed",1);
		me->add("gift/str/all", 1);
		me->add("str", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s ����%-10s������%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "����","str",ctime(time())));
	}
// ����
	if (me->query("gift/con/all") < 10 && me->query("con") < 35 && random(2))
	{
		effect++;
//		write(HIC "������Լ�����Ϣ��ͨ���ˡ�\n" NOR);
		write(HIC "��ĸ��������ˡ�\n" NOR);
		me->add("gift/con/succeed",1);
		me->add("gift/con/all", 1);
		me->add("con", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s ����%-10s������%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "����","con",ctime(time())));
	}

//��
	if (me->query("gift/dex/all") < 10 && me->query("dex") < 35 && random(2))
	{
		effect++;
//		write(HIR "������Լ����ȽŸ�����ˡ�\n" NOR);
		write(HIR "����������ˡ�\n" NOR);
		me->add("gift/dex/succeed",1);
		me->add("gift/dex/all", 1);
		me->add("dex", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s ����%-10s������%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "��","dex",ctime(time())));
	}	
// ��Ե
	if (me->query("gift/kar/all") < 10 && me->query("kar") < 35 && random(2))
	{
		effect++;
		write("��ĸ�Ե����ˡ�\n" NOR);
		me->add("gift/kar/succeed",1);
		me->add("gift/kar/all", 1);
		me->add("kar", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s ����%-10s������%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "��Ե","kar",ctime(time())));
	}
// ��ʶ
	if (me->query("gift/cor/all") < 10 && me->query("cor") < 35 && random(2))
	{
		effect++;
		write("��ĵ�ʶ����ˡ�\n" NOR);
		me->add("gift/cor/succeed",1);
		me->add("gift/cor/all", 1);
		me->add("cor", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s ����%-10s������%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "��ʶ","cor",ctime(time())));
	}

// ����
	if (me->query("gift/cps/all") < 10 && me->query("cps") < 35 && random(2))
	{
		effect++;
		write("��Ķ�������ˡ�\n" NOR);
		me->add("gift/cps/succeed",1);
		me->add("gift/cps/all", 1);
		me->add("cps", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s ����%-10s������%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "����","cps",ctime(time())));
	}
// ����
	if (me->query("gift/spi/all") < 10 && me->query("spi") < 35 && random(2))
	{
		effect++;
		write("�����������ˡ�\n" NOR);
		me->add("gift/spi/succeed",1);
		me->add("gift/spi/all", 1);
		me->add("spi", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s ����%-10s������%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "����","spi",ctime(time())));
	}
// ����
	if (me->query("gift/sta/all") < 10 && me->query("sta") < 35 && random(2))
	{
		effect++;
		write("�����������ˡ�\n" NOR);
		me->add("gift/sta/succeed",1);
		me->add("gift/sta/all", 1);
		me->add("sta", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s ����%-10s������%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "����","sta",ctime(time())));
	}
// ��ò
	if (me->query("gift/per/all") < 10 && me->query("per") < 35 && random(2))
	{
		effect++;
		write("�����ò����ˡ�\n" NOR);
		me->add("gift/per/succeed",1);
		me->add("gift/per/all", 1);
		me->add("per", 1);
		log_file("gift/tianfu",
		        sprintf("%-20s ����%-10s������%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        "��ò","per",ctime(time())));
	}
	if (! effect)
		tell_object(me, "��������ú���ûʲô���á�\n");
		destruct(this_object());
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}

