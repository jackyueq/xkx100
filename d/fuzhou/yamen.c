// Room: /d/fuzhou/yamen.c
// Date: may 12. 1998 Java

inherit ROOM;

void create()
{
	set("short", "�ᶽ����");
	set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ���
���ӷַ���ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ�������ʲ��վ����ǰ��
LONG );
	set("exits", ([
		"east" : __DIR__"nandajie",
	]));
	set("objects", ([
		__DIR__"npc/geshiha" : 2,
	]));
	set("no_fight", "1");
	set("no_beg", "1");
	set("coor/x", 1830);
	set("coor/y", -6310);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("geshiha", environment(me))) && dir != "east")
		return notify_fail("��ʲ���ȵ�����ʩ������ȥУ���ı��������θɣ���\n");
	return ::valid_leave(me, dir);
}
