// xianzhentang.c ������
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǵ����Աߵ�һ��������Ҳ�ǽӴ���Ҫ���˵ĵط���������
ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ���ɽ��ˮ���辰��ǽ
���Ϲ���һЩ�ֻ���������һ��ҩ���ң�����ҩ�ĵط���
LONG
        );

        set("exits", ([
                "east" : __DIR__"piandian",
                "west" : __DIR__"yaojishi",
                "north" : __DIR__"datang1",
                "south" : __DIR__"rongwutang",
        ]));
        set("no_clean_up", 0);
        set("objects",([
                CLASS_D("quanzhen")+"/zhang" : 1,
        ]));

	set("coor/x", -2800);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}