// Room: /yangzhou/zhuqidian.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
���񲻲������ݣ�������Ʒ��������������������ݾ����ɽ�
���ĵ�̱��Ƶ�������ľ������ǽ��ǽ������������¨�����ֵ�ƽ���
�յ��ճ���Ʒ���м�Ĺ�̨���űʼܡ���Ͳ��С����ľ�����ǽ����
�����հ����档������ĵ�����һ��������Ц������ӭ��������
LONG );
	set("exits", ([
		"north" : __DIR__"matou",
	]));
	set("objects", ([
		__DIR__"npc/liusanshun" : 1,
	]));
	set("coor/x", 40);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}