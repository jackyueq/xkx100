// Room: /d/chengdu/southchengmen.c
// Last Modifyed by Winder on Jan. 4 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "�ϳ���");
	set("long", @LONG
�ɶ����ţ�����ͷ���²�̫ƽ���ټ��ϳɶ������������Ǳ�����
��֮Ҫ�壬��Ȼ���̲����ܡ������ש����ĳ�ǽ�����������٣�Ҳ��
֪�����ж��ٸ���ͷ�ˡ��سǵı��²�������ĵ����㣬�ڴ��ǻ���Ҳ
�׼�����ʲô���£��㲻�ɵüӿ��˲�����
    ��·�ϱ����졣
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"north" : __DIR__"nanjie",
		"south" : __DIR__"nanheqiaos",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -8050);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

