// Room: /d/chengdu/chenmapo.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "���Ŷ�����");
	set("long", @LONG
��������������µĳ����Ŷ����ꡣ����������İڷ���ʮ���ź�
�᷽����һ����˾�������Ʒ�������Ŷ������������æ������ͷת��
����̨�ϰ�����̳������족��һ�����̣���������ŵľ��ǳ����š�
LONG	);
	set("exits", ([
		"east" : __DIR__"chufang",				
		"west" : __DIR__"beijie1",				
	]));
	set("objects", ([
		__DIR__"npc/mapo" : 1,
	]));
	set("coor/x", -8040);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

 
