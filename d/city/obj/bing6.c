// /d/city/obj/bing6.c ״Ԫ��

inherit ITEM;
#include <ansi.h>

mapping attr = ([
	"str" : "����",
	"con" : "����",
	"dex" : "��",
	"sta" : "����",
	"kar" : "��Ե",
	"cps" : "����",
	"cor" : "��ʶ",
	"per" : "��ò",
	"spi" : "����",
]);
	
void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(RED "״Ԫ��" NOR, ({"bing6", "zhuangyuanbing"}));
	set("unit", "��");
	set("long", "����һ��Ψһ��״Ԫ����\n");
	set("no_get", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_beg", 1);
	set("no_steal", 1);
	setup();
}

int do_eat(string arg)
{
	int i;
	object me=this_player();
	
	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if (!wizardp(me) && query("owner") != me->query("id"))
	{
		write(HIR"��ֻ�ܳ��Ը�Ӯ���ı���\n"NOR);
		return 1;
	}
	if(arg=="bing6"||arg=="zhuangyuanbing")
	{
		me->add("combat_exp",1968);
		me->add("potential",888);
		i = random(9);
		me->add(keys(attr)[i], 1);
		log_file( "bobing", sprintf("%s %s\n", me->query("id"), keys(attr)[i]));
		log_file("gift/tianfu",
		        sprintf("%-20s ����%-10s������%s(%s) [%s]\n",
		        me->query("name")+"("+me->query("id")+")",
		        base_name(this_object()),
		        values(attr)[i],keys(attr)[i],ctime(time())));
		message_vision(HIY "$N�������ڳ���һ��$n��\n" NOR, this_player(), this_object());
		tell_object(me, "���"HIG + values(attr)[i] + NOR"�����ˡ�\n");
		destruct(this_object());
	}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}

