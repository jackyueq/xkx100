// Room: /d/lingxiao/jianyusun.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "�η�");
	set("long", @LONG
����һ��СС���η�����һ�����������ʯ�ҡ����¸ߵͲ�ƽ����
�Ǿ�ʯ���������۾����²쿴��ֻ�������������΢��͸�룬��Ŀ��ȥ��
�Ǹ�����һ�߼����Ķ�Ѩ��è����ɳ��룬ȴ��С��Ҳ�겻��ȥ������
��ʱ�õ�С�ס�
LONG );
	set("exits", ([
		"east" : __DIR__"laolang",
	]));
	set("objects", ([ 
		__DIR__"npc/sun" : 1,
	])); 
	set("coor/x", -31000);
	set("coor/y", -8900);
	set("coor/z", 130);
	setup(); 
	replace_program(ROOM);
}

