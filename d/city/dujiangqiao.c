// Room: /yangzhou/dujiangqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","�ɽ���");
	set("long",@LONG
һ������ʯ�ź����ڴ��˺��ϣ��ŵĲ�������֪��ŷ�������š���
���š������¸�ɫ��ֻ������Ϣ������������������ͷ�����˵���ʳ��
���������Σ����ڴ�װж�������ž������ݵ����ţ������š�
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"north"  : __DIR__"nanmen",
		"south"  : "/d/wudang/wdroad1",
	]));
	set("objects", ([
		"/d/beijing/npc/shisong" :1,
	]));
	set("coor/x", 10);
	set("coor/y", -110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
