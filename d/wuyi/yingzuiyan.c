// Room: /d/wuyi/yingzuiyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "ӥ����");
	set("long", @LONG
����ӥ���������ף���๰�ͷʵ���桱��ӥ������һ����Ȼһ���
���ң���ͺͺ���Ҷ���������ǰͻ����������๣�����һֻչ�����ɡ�
�������յ���ӥ���ഫ������һֻ������Ů��ħӥ������ڽ�������ʱ
�����������Ҳ�����������ˡ�����������ڵ���ѪҲ���������
�·绯��һ����ʹ����Ѻۣ�����������ͣ���ɲ��ϵĹ��ޡ�
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"path12",
		"north"     : __DIR__"path13",
		"southeast" : __DIR__"path14",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -4920);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

