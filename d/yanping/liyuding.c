// Room: /d/yanping/liyuding.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "���㶥");
	set("long", @LONG
���㶥���཭�ϣ���ͷ����������ֱָ���ģ���������ˮ������
�ļ����������첻����ɽ��һ��ʵ�İ˲�ʯ������Խ��ŷ�ɽ������ң
ң��ԡ�
LONG );
	set("exits", ([
		"southup"   : __DIR__"dongta",
		"northeast" : __DIR__"guandao3",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
