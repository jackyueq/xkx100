// Room: /d/heimuya/shandao2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "ɽ��");
	set("long", @LONG
��һ·��ɽ�����Ƽ��գ�������������ȣ���ɽ����֮����խС��
����һ�����񣬱ؽ���ɥ�ڴˡ�
LONG    );
	set("outdoors", "heimuya");
	set("exits", ([
	    "eastdown" : __DIR__"shandao1",
	    "westup"   : __DIR__"shijie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3220);
	set("coor/y", 4200);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}