// Room: /d/wuxi/qingmingqiao.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������������������һ�����ţ���ԭ�������ţ�Ҳ�������š���
���˺��ڳ����������۵����ʣ��ֻ㵽����Ļ��Ǻ��С��������Ϻ�ɫ
�����ɫ�Ļ���ʯ���ɣ�վ�����п�������������������
LONG );
	set("outdoors", "wuxi");
	set("exits", ([
		"north" : __DIR__"southgate",
		"south" : __DIR__"road7",
	]));
	set("no_clean_up", 0);
	set("coor/x", 370);
	set("coor/y", -850);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}