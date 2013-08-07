// Room: /city/wudao3.c
// Date: Feb.28 1998 by Java
#include <ansi.h>;
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "�����");
	set("long", @LONG
���������滷ɽ��ֻ�б����������ڵ�һƺɽ��ƽ�ء�ɽ��ɽ����
���λ������죬ɽ���µ�ƽ���̲������м��Ѿ������˸���̨������
һ���ȥ��������������α����ȫ������������쿪ʼ�ˡ�
    ��������һ���ʾ��(gaoshi)��
LONG );
        set("outdoors", "yangzhouw");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"leitai"      : __DIR__"leitai",
		"northeast"   : __DIR__"wudao1",
		"northwest"   : __DIR__"wudao2",
	]));
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_beg", "1");
	set("coor/x", -20);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_quit","quit");
	add_action("do_quit","exit");

	add_action("do_quit","exercise");
	add_action("do_quit","dazuo");
	add_action("do_quit","exert");
	add_action("do_quit","yun");
	add_action("do_quit","learn");
	add_action("do_quit","xue");
	add_action("do_quit","respirate");
	add_action("do_quit","tuna");
	add_action("do_quit","perform");
	add_action("do_quit","persuade");
	add_action("do_quit","quanjia");
	add_action("do_quit","practice");
	add_action("do_quit","lian");
	add_action("do_quit","study");
	add_action("do_quit","du");
	add_action("do_quit","teach");
	add_action("do_quit","jiao");
}

int do_quit(string arg)
{
	write(this_player()->query("name")+"�����ڸ�ɶ����ѽ��ר�Ŀ�����ɣ�\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	object obj;
//	if ((dir == "leitai") && (!me->query_temp("leitai_allow")) && !wizardp(me))
//		return notify_fail("��û��������أ���Ｑ��ȥ��\n");
//	if ((dir == "leitai") && (me->query_temp("leitai_allow")))
	if (dir == "leitai")
	{
		me->delete_temp("leitai_allow");
		me->delete_temp("view_leitai");
		me->set("no_get", 1);
	}
        return ::valid_leave(me, dir);
}
string look_gaoshi()
{
	return 
HIR"\n\n                           
                 ������һ�ٵı�����
\n"HIY"
��һ��ÿ�µ�ʮ������ʮ��ʱ��ʮ�־��б����ᡣ�����ص���������
      �������������
�ڶ�������������У�ÿ�������ʽ��ʼ֮ǰ���μӱ���������ֵ��
      ʦ�������������£�
      ��ʮ�������� ����100�������� ����100��~300����
      ����300��~500���� ����500��~1000���� ����1000��������
      ���ĳһ����ֻ��һ�˱����μӣ�����ֱ�ӻ�ø���ھ���
����������ʵ����̭�ơ�
      ���������ʵ��������ʤ���⣬��Ϊһ����ʤ����ʤ�߽�����һ
      �֣�������ʤ�ƣ���һ�ֱȽϱ����ϵĹ��򣬵ڶ�����ȭ���Ͼ�
      �����£���������ѡ����ʤ�߻�ø���ھ���
���ġ�Ϊʹ���µ�һ��ʵ���������ʹ�����������书������perform��
      powerup��enforce��poison�ȣ���roar��������Ӱ���������
      ���л��ʹ�á�Υ��ͣ����
���塢����ʱ���ñ����ͷ���������̨�ϵı�������������ȡ�����о���
      ��ֹʹ��������������ֹʹ�ý�˿�ס���⬼ס���˿���ף���ֹ
      ʹ���˺�������50�ı����簽��ذ�ס����콣����ħ���ȡ�
����������ʱ��ע�����У�����ŭ�ߡ�Υ���ֳ���ʦ�����ߣ�ȡ����һ
      ������ʸ�
"HIG"                                      ������  ����
\n"NOR;
}