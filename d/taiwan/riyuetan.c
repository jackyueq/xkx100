// Room: /d/taiwan/riyuetan.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����̶");
	set("long", @LONG
����̶λ����ɽ֮�����ܸ�ɽ֮�ϣ�����������̶��˫̶�ȳƺ���
�����ڴ�һ��̶ˮ���ܵ��������������Ϊ��ˮ�纣��������̶֮����
�ഫ��֮��̶�и��������죬����Ϊ�籱���������֣��ϰ�����¹���
����ˮ���ɽ�򼯼���ɽ�ϸ���������Բ��顣����̶֮����������
�ܴ�廷������ˮ�����������������Σ���ɫ�����续������̶�˾���
̶�и��졢̶�ھ����������𡢶�ľ���ۡ�ˮ�糯ϼ����Ҷ��Ǯ����
��������ɽˮ����ȣ�Զ������𣬱㾪��������ī���Ƹе��ġ�
LONG );
	set("exits", ([
		"northwest" : __DIR__"banxianshe",
	]));
	set("objects", ([
		__DIR__"npc/shaozhuren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2520);
	set("coor/y", -7010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

