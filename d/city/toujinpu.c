// Room: /yangzhou/toujinpu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","�׼�ͷ����");
	set("long",@LONG
�׼�����ͷ��ñ�ӣ��������࣬ʽ��ҲƯ�������ݳǵ������˶ൽ
����ѡһ���Լ�ϲ����ͷ�����ڶ��߷���һ�ź�������������˸�ʽ
��ͷ��ñ�ӣ����˿���������Ŵ�����ʽͷ��ñ�ӣ����߷��ż���ͭ����
����С�������ڱ��Դ���ʽͷ�����վ��ӡ�
LONG );
	set("exits", ([
		"north" : __DIR__"caiyixijie",
	]));
	set("objects", ([
		__DIR__"npc/kongjinjin" : 1,
	]));
	set("coor/x", 50);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}