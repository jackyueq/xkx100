// Room: /d/chengdu/eastroad2.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���Ϻ���");
	set("long", @LONG
���Ų������˸��Ϻ��ϣ�������Ǳ���Ϊ�ɶ�ĸ�׺ӵĸ��Ϻӣ���
�����������Ʈ�����̲����𣬲ʵ��׷ɡ���ˮ�峺���ף����������
ȥ���ӵĶ԰���Ⱥϴ�¸��ˣ�һ�����ڵ�������һ�ߴ��������죬����
Ц���ںӵ���߶�����������Զ�����и������̶��Դ������������
��Ҳ�·��뻭�ˡ�
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"southeast" : __DIR__"funanhe2",
		"northwest" : __DIR__"chunxilu3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}

