// Room: /d/yanping/ximen.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ⱥɽ�ˡ���Ŀ��������Ϫ������Ⱥ���ã��������ͨ��
�������ϵ�Ҫ������ש��ǽ�Ϲ���һЩ��ʾ�ͺ������顣��ƽ��������
����������֪����Ϊ��ѧ������Ҳ��
LONG );
	set("exits", ([
		"east"      : __DIR__"road3",
		"north"     : __DIR__"sixianci",
		"southwest" : __DIR__"gudao4",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 1,
	]));
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
