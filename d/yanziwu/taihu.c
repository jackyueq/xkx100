// Room: /d/yanziwu/taihua.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "̫��");
	set("long",@LONG
������Ů����΢Ц���紺���㽿����覡����ֻ�������ʱ��ժ��ʵ
Ϸˣ��������������:  "��������ʮ���飬С��̰Ϸ�����١�����Ūˮ
��ͷ̲��Ц�Ѻ�ȹ��Ѽ����" �������浭����ɢ�������������
LONG );
	set("outdoors", "yanziwu");
	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
