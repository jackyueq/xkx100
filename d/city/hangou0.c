// Room: /city/hangou0.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����������Ҫ�����ϱ����˺ӵģ���һ�εĴ��˺ӳ�Ϊ����˺ӡ�
�����������ڴ˻�������˺ӵġ����ڿ����ӿڣ�����Ľ�ͨ���ӷ�æ��
���ڰ��ϣ�����Ĵ�ׯҲ����ĳ��ܣ����д����С�۳�û�ڴ�֮�䣬
�似�����ܲ�������̾�� 
LONG );
	set("exits", ([
		"west" : __DIR__"hangou1",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

