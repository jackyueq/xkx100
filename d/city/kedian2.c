// Room: /yangzhou/kedian2.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "�ػ���Ԣ��¥");
	set("long", @LONG
�������ڿ�Ԣ��¥�������ϣ����������ͷ��ﲻʱ�ش���������
��������һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������¥�µ�
�ƹ񴦸���Ǯ������˯����
LONG );
	set("exits", ([
		"down"  : __DIR__"kedian",
		"enter" : __DIR__"kedian3",
	]));

	set("objects", ([
                CLASS_D("shaolin") + "/xingzhe" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -20);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}