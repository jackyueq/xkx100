// yangwanxiao.c

inherit NPC;
#include <ansi.h>

string ask_room1();

void create()
{
	set_name( YEL "������" NOR, ({"yang wanxiao", "yang", "wanxiao"}) );
	set( "age", 48 );
	set( "int", 25 );
	set( "con", 26 );
	set( "per", 22 );
	set( "attribute", "peaceful" );

	set( "long", @LONG
����������������壬����������ֽ�����ˣ��������룬
����ȥ�������ţ���˵������ʫ�����ļ��ã�������֪����
���ѣ���������ʫ��͡�
LONG);
	set( "combat_exp", 10000 );
	set_skill( "literate", 100);

	set("chat_chance", 30);
	set("chat_msg", ({
		"������ֻ�ǳ����΢΢һЦ��ȴʲôҲ��˵��\n",
	}) );
	set( "inquiry", ([
		"С����ɽ��" : (: ask_room1 :),
		"�" : (: ask_room1 :),
		"����" : "������������ҹ�����ζ��������ݣ�����������\n",
	]) );
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object(__DIR__"obj/chuan")->wear();
}


string ask_room1()
{
	return "�����������µģ�����ȴҲ����Щ��ɫ�ˡ�\n";
}

