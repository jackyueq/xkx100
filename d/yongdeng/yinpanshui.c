// Room: /huanghe/yinpanshui.c
// Java Sep. 22 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "Ӫ��ˮ");
	set("long", @LONG
�����ǵ��������޳���ʱפ���ĵط��������ξ��з�����������
�Դ�����פ�����˺ü�����ˮ����ʹʿ���ǲ��ú��ֿ���ɬ����ˮ��
�����˵صİ����ǽ�����ΪӪ��ˮ��������ľ�Ϊ�����񾮡���
LONG );
	set("exits", ([
		"southwest" : __DIR__"bingcao",
	        "southeast" : __DIR__"shimen",
                "northeast" : __DIR__"guchangcheng",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yongdeng");
	set("coor/x", -20000);
	set("coor/y", 30000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}