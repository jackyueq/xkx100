// Room: /d/nanshaolin/gulou3.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��¥����");
	set("long", @LONG
���������ƺ�Խ��Խխ��¥��Ҳ��Ϊ���ơ������ϲ����໵������
����ľ����ɫҲ���¾ɲ�ͬ���Ӵ������������������Կ��������еĲ�
��¥�ͷ���¥¶������һ�ǣ���������ǰ����ݶ����ݼ������˸����
�ġ����֡�
LONG );
	set("exits", ([
		"up"   : __DIR__"gulou4",
		"down" : __DIR__"gulou2",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

