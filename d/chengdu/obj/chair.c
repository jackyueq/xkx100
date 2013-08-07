// Room: /d/chengdu/obj/chair.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>
inherit ITEM;

void create()
{
	string *pname = ({"����", "˿��", "����","����" });
	string *mname = ({"", "��", "����", "����", "����", "�۵�" });
	string *lname = ({"����", "����" });
	string name;
	string zname = lname[random(2)];
	name = sprintf("%s%s%s",pname[random(4)],mname[random(6)],zname);
	set_name( name, ({ "chair" }));
	set("class", zname);
	set_weight(30000);
	set("long", "����һ�����ӡ�\n" );
	set("no_sell", "�������������������");
	set("no_get","����˵��,�����ǹ��ҵĲƲ�,�κ��˶���������");
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("material", "wood");
		set("value", 2000);
//		set("amount",30);
	}        
	setup();
}
void init()
{
	add_action("do_sit", "sit");
	add_action("do_tang", "tang");
	add_action("do_stand", "stand");
}

int do_sit(string arg)
{
	object ob, who;
	string str;

	if( !arg || arg == "" ) 
		return notify_fail("��Ҫ��ʲô��\n");
	ob = this_object();
	who = this_player();
	if( arg != "chair" && arg != "����" && arg != ob->name() )
		return notify_fail("����û��" + arg + "\n");
	if( who->query_temp("rode") )
		return notify_fail("�����ڲ��ڵ��ϣ���ô����\n");
	if( (int)ob->query("rode") >= 3 ) 
		return notify_fail( ob->name() + "�Ѿ������ˣ�\n");
	if( ob->query("class") == "����" && ob->query("tang") ) 
		return notify_fail( ob->name() + "�Ѿ��������������ˣ�\n"); 

	who->set_temp("rode/type", "sit");
	who->set_temp("rode/desc", "����" + ob->name() + "��");
	ob->add("rode",1);
	ob->set("no_get", "�������������ģ�\n");
	message_vision("$Nһƨ��������" + ob->name() + "�ϡ�\n", who);
	return 1;
}

int do_stand()
{
	object ob,who;
	int max_qi;
     
	ob = this_object();
	who = this_player();
	if( who->query_temp("rode/type") != "sit")   
		return notify_fail("�㱾����û�����ţ�\n");
	who->delete_temp("rode");
	if( ob->query("tang") ) ob->delete("tang");
	else if( ob->query("rode") ) ob->add("rode", -1);
	if( !ob->query("tang") && !ob->query("rode") ) ob->delete("no_get");
	max_qi = (int)who->query("max_qi");
	if( (int)who->query("qi") > ( max_qi - max_qi/4) )                 
		if( random(1) == 1) 
			message_vision("$Nһ�������ͦ��" + ob->name() + "�ϵ���������\n", who);
		else
			message_vision("$N��ಡ���һ������" + ob->name() + "��վ��������\n", who);
	else
		message_vision("$N��������������֣���" + ob->name() + "�ϻ�����վ��������\n", who);
	return 1;
}
int do_tang(string arg)
{
	object ob,who;
	string str;

	if( !arg || arg == "" ) 
		return notify_fail("��Ҫ����ʲô�ϣ�\n");
	ob = this_object();
	who = this_player();
	if( arg != "chair" && arg != "����" && arg != ob->name() )
		return notify_fail("����û��" + arg + "\n");
	if( who->query_temp("rode") )
		return notify_fail("������ûվ�ţ��������¡�\n");
	if( ob->query("tang") )                 
		return notify_fail( ob->name() + "�Ѿ��������ˣ�\n");
	if( ob->query("rode") )
		return notify_fail( ob->name() + "�Ѿ��������ˣ�\n");        
	who->set_temp("rode/type", "sit");
	who->set_temp("rode/desc", "����" + ob->name() + "��");
	ob->set("tang",1);
	ob->set("no_get", "�������������ģ�\n");
	message_vision("$N��һ̲������������" + ob->name() + "�ϡ�\n", who);
	return 1;
}

