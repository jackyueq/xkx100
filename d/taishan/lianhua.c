// Room: /d/taishan/lianhua.c
// Last Modified by Winder on Aug. 25 2001
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ʵ��������ɽ���ܴض��ɣ�״������������Ϊ����������
Σ�����𣬽��廨�¡�����������󣬿ɿ������̵��е�������С�ϰ�
�������󣬹ʴ��������ֽ����˷塣�����߱���������ķ嶥��
LONG );
	set("exits", ([
		"northup" : __DIR__"shixin",
		"westup"  : __DIR__"tianjie",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 430);
	set("coor/y", 620);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
