// Room: /d/chengdu/mujiangpu.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;
void create()
{
	set("short", "ľ����");
	set("long", @LONG
����һ�Ҽ�ª��ľ���̣�һ������ľ�������ڵ��϶�������ֵ����
����ľ����Ҳֻ������Щ��ǹ����ʲô�������Һ��ڡ����Ϻ�ǽ������
�ضѷ���һЩľ����ľ����ľ��ʲô�ģ����м�������ӣ�����һ���
ľ�����ߡ�
LONG	);
	set("objects", ([
		__DIR__"npc/mujiang" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"xijie2",
	]));
	set("coor/x", -8060);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

