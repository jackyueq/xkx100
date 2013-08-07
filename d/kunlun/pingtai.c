// Room: /d/kunlun/dashibi.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIW"��ƽ̨"NOR);
	set("long", @LONG
ǰ����һ������Ҳ�ƵĴ�ɽ�ڡ���ǰãã�ƺ�������ȥ·���㾹��
������һ������Կյļ���ƽ̨�ϡ���ƽ̨����ʮ���ɷ�Բ�����ǰ���
�ٿգ��ϼȲ��ã����ֲ��ܣ���������·һ�������ƽ̨�ϰװ����Ķ�
�Ǳ�ѩ���������֣�����Ұ�ޡ�Ψ��ƽ̨����һ������(tree)��
    ����ǰ����һ�����������ɽ�ں�������ƺ��и���Ѩ��ɽ�ڲ��
�����ƺ��и�Сɽ��(dong)��
LONG );
	set("exits",([
		"west" : __DIR__"xsxiepo2",
	]));
        set("item_desc", ([
		"tree": "һ��ͦ�ν�˶��������\n",
                "dong": "һ����֪��ǳ��ɽ����\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "hongmei");
	set("coor/x", -100000);
	set("coor/y", 20010);
	set("coor/z", 40);
	setup();
}
void init()
{
	add_action("do_enter","enter");
	add_action("do_climb","climb");
}
int do_enter(string arg)
{
	object me = this_player();
	int n = me->query("str");
	if( !arg || arg != "dong")
	{
		write("�����ʲôѽ?\n");
		return 1;
	}
	message_vision("$N������һ�������������Ŷ�����������\n", me);
	if(n < 20 || wizardp(me))
	{
		message_vision("$N�������ɣ�����ǰ��͸�����������д�ϲ�������ʩ������ǰ�С�\n", me);
		me->move(__DIR__"cuigu");
	}
	else
	{
		message_vision( HIR"$N��ŭ֮�£�����˫�磬��ǰһ�������ӹ�Ȼǰ���˳�����������ǰ�У�ȴ������\n�ܣ���Ӳ��ʯ��ѹ�����ؿڱ��ģ���Ȼ��Ҳ����������$N��Ϣ���ܣ�ֻ�ú��ˣ�������\n��Ƕ�ڼ�ʯ֮�У�ǰ�����ǲ��ܣ�����ȴҲ�Ѳ��ã���һ��$N�ŵû����ɢ���߾���ƽ\n֮����˫����ʯ�����ƣ����Ӳ����˳����;����ؿ�һ���ʹ������������һ���߹ǡ�\n"NOR, me);
		me->receive_damage("qi", 45);
		me->receive_wound("qi", 40);
	}
	return 1;
}
int do_climb(string arg)
{
	object me = this_player();
	if( !arg || arg != "tree")
	{
		write("�����ʲôѽ��\n");
		return 1;
	}
	message_vision("$N����������ҡ����ҡ�������Ƿ��ʵ��\n", me);
	message_vision("$N��Ȼһ��ʧ�֣���������ֱ����ȥ��\n", me);
	me->move(__DIR__"xuedi");
	me->receive_damage("qi",100 - me->query_dex());
	me->receive_wound("qi",100 - me->query_dex());
	me->unconcious();
	return 1;
}
