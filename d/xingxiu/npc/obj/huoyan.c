// Room: /d/xingxiu/npc/obj/huoyan.c
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>;
inherit ITEM;
void create()
{
	set_name(HIR"����"NOR, ({ "huo yan"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",HIR"�����Լ�ߣ�ɫ�����̣�����ɭɭ����Ѱ��������졣\n"NOR );
		set("no_get", 1);
		set("value", 1);
		set("unit", "��");
		set("fire_name", "����");
		set("weight", 30000);
		set("location", 1);
	}
	setup();
}

void init()
{
	if(base_name(environment(this_object()))!="/d/xingxiu/riyuedong")
	call_out("dest", 300);   
	remove_call_out("change");
	call_out("change", 50); 
}

string *fire_msg = ({BLU"����"NOR,RED"����"NOR,WHT"����"NOR,GRN"����"NOR,MAG"����"NOR});

void change()
{
	string msg = fire_msg[random(sizeof(fire_msg))];
	tell_room(environment(this_object()),this_object()->name()+ HIR"��Ȼһ�������Ż�ⱬ������Ȼ������ɫ�������������ޱȣ�\n"NOR);    
	this_object()->set("name", msg);    
	remove_call_out("change");
	call_out("change", 50);  
}
 
void dest()
{
	tell_room(environment(this_object()),HIR"���潥����Ϩ���ˡ�\n"NOR);
	destruct(this_object());
}
