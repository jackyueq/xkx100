// Room: /d/taishan/wangheting.c
// Last Modified by Winder on Aug. 25 2001

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
����������������ͤ���ƺӽ��Ϊ̩ɽ�������֮һ����������
����Ϧ������ʱ����Ŀ��������̩ɽ���������͵ľ�ͷ���ɿ����ƺ�
��һ����ɫ�Ĵ����������⣬���ˮ���䵽��գ��γ��׾����������ԣ�
�ư���䣬��ͬ�����̾�һ�㣬��������������һֱ������ؽ��紦��
ǡ��Ԭö�ڡ���̩ɽʫ���������ģ���һ����ˮ���´�����������ͨ
���ӡ��� 
LONG );
	set("exits", ([
		"east" : __DIR__"yuhuang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 350);
	set("coor/y", 780);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
