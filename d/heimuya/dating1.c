// Room: /d/heimuya/dating1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���ǡ�������̡��µ�һ���ã������õĴ�������Ŀ��ȥ��������
�ģ���������һ������(vote)��
LONG    );

	set("exits", ([
		"south" : __DIR__"grass2",
		"northdown" : __DIR__"linjxd5",
	]));
 
	set("objects",([
		__DIR__"npc/jiaotu" : 2,
	]));
	set("item_desc", ([
		"vote": "������̣��ĳ���£��󱻲�����\n"
	]) );
//	set("no_clean_up", 0);
	set("coor/x", -3030);
	set("coor/y", 4030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}