// dadao1.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�غ����");
        set("long", @LONG
һ�����Ĵ����ȴ����ϡ�١�ԭ��������·ס�ŵĶ��Ǵ�ٹ�
�ˡ������羰����֮����ȴ�Ե�һƬ��ɪ��·��������һ��ׯ԰����
�����ϱ����졣
LONG);
        set("exits", ([
            "north"     : __DIR__"road5",
            "south"     : __DIR__"dadao2",
            "west"      : __DIR__"guozhuang",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/baiwei" : random(2),
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4070);
	set("coor/y", -1450);
	set("coor/z", 0);
	setup();
}
