// Room: /d/heimuya/shimen.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����һ����ʯ��ǰ��ֻ��ʯ�����Կ������д��֣������ǡ��ĳ���
�¡��������ǡ�����Ӣ����������Ͽ��š����¹������ĸ�����֡�
LONG  );
	set("outdoors", "heimuya");
	set("objects", ([
		CLASS_D("heimuya")+"/zhang2" : 1,
	]));
	set("exits", ([
	    "eastdown" : __DIR__"shijie2",
	    "westup"   : __DIR__"up1",
	]));
//	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4200);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}