// yuefen.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
Ĺ��������ʯ����ʯ��ʯ����������١����йŰؽ��£��������ɵ�
��Ĺ��Ĺ�����š���������Ĺ��������Ĺ�����棬��������֮�����Ƶ�Ĺ��
Ĺ���Ͽ��š��μ��Һ�����֮Ĺ����������ǰ�������ĸ�����(statue)����
��ǽ�����ĸ�����(word)��
LONG);
        set("exits", ([
            "south"     : __DIR__"yuelang",
        ]));
        set("item_desc" , ([
            "statue" :
"��������������������������ϣ��ϱ�������ͬıɱ�����ɵļ鳼��
�ſ�����ٹм���ĸ����񶼷������֣�����Ĺ���š�\n",
            "word"   :
"ǽ���С����ұ������ĸ����֡�������ĸ����ѵ��ʱ�����ɱ��Ͽ̵��֡�\n",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xihu");
	set("coor/x", 4080);
	set("coor/y", -1400);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
