// Room: /d/yueyang/chaguan.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ƕ�ͥ
����ζ������������������ģ������Ҳ�ڲ�������Ŷ����ȺȲ衣һЩ
��������Ŀ��̺ͺ���䤱��Ŀ��������Գ�һ�ѣ�����Ʒ����¿������
����̬��
LONG );
	set("resource/water", 1);
	set("exits", ([
		"north" : __DIR__"dongjie",
	]));
	set("objects", ([
		__DIR__"npc/chaboshi" : 1,
		__DIR__"npc/xingren" : 1,
	]));
	set("coor/x", -1400);
	set("coor/y", -2280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
