// Room: /city/zoulang2.c
// Last modified by winder 2002.11.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "����");
	set("long", @LONG
���Ƕĳ�������ȣ�����������С�����������ֶ�ͽ������������
������ɢ���̾ƺ�����ʵ���Ƿ��ӡ���������ķ�����ƾš����Ӻ�
�齫�ɻ��������ΰ���Ƶ����������Ʊ��������������������ӳ���
���˼����˷ܵ����ա���һ�߽��������̾�������Ǻõط���
LONG);
	set("exits", ([
		"north"  : __DIR__"qiyiting",
		"south"  : __DIR__"youxiting",
		"west"   : __DIR__"zoulang1",
	]));
        set("no_fight","1");
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("coor/x", 21);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
void init()
{
	object me = this_player();
	if (me->query("gender") != "����")
		set("long", @LONG
���Ƕĳ�������ȣ�����������С�����������ֶ�ͽ������������
������ɢ���̾ƺ�����ʵ���Ƿ��ӡ���������ķ�����ƾš����Ӻ�
�齫�ɻ��������ΰ���Ƶ����������Ʊ��������������������ӳ���
���˼����˷ܵ����ա���һ�߽����������üͷ��ʲô��ط���
LONG);
	return;
}
