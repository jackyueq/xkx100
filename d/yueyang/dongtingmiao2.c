// Room: /d/yueyang/dongtingmiao2.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��ͥ���޵�");
	set("long", @LONG
�޵��ڶ�ͥ��������档�޵�Ϊ�����С��Ů�������񣬴��Ϊ��
��Ъɽʽ�����������ڶ�ͥ����Ϊƽ��������˺ܶ���£�����Ϊ�˼�
���������ھ�ɽ����ͥ�������������Ů��
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"dongtingmiao1",
	]));
	set("coor/x", -1660);
	set("coor/y", 2360);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
