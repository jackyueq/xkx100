// rongwutang.c ������
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ȫ������֮��̷���˵ľ��ң���䷿����ʰ�ĺ���ͨ����
��ûʲô����ֻ��һ����Ⱦ��ǽ��б����һ�ѱ�����
LONG
        );
        set("exits", ([
                "north" : __DIR__"xianzhentang",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/tan" : 1,
        ]));
	set("coor/x", -2800);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}