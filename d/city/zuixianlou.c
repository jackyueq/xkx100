// Room: /city/zuixianlou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
��Բ����������������¥����˵�����˲�֪�����˲�����������ѧ
ʿ���ε��ˣ�������¥�Ļ�����޲����ڣ���ȻΪ�����ң�����һ�δ�
�麣�ڵļѻ����Ӵ�����¥��������¥�²��ü��ף��˿Ͷ��ǴҴҵ�
���ˣ������ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����������
LONG );
	set("exits", ([
		"south" : __DIR__"ganquanjie",
		"west"  : __DIR__"shilijie3",
		"up"    : __DIR__"zuixianlou2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}