// wanwutang.c ������
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ȫ������֮������һ�ľ��������䲻����ʰ��������
�࣬ǽ�Ϲ���һ��һ�ٺ�һЩ�ֻ���С���ϰڷ�����ֽ�ͻ�ī�Ǻ���
��֪��������Ҫ���ֻ��ǻ滭��
LONG
        );
        set("exits", ([
                "south" : __DIR__"huizhentang",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/wangchuyi" : 1,
        ]));

	set("coor/x", -2800);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}