// Room: /d/lingxiao/houyuan1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","��԰");
	set("long",@LONG 
�����������ɵĺ�԰��С����ˮ�������͸󡣲�̨�ʴ䣬�ϳ�������
�ɸ������������޵ء���������ѩɽ֮�ϣ���������ů�紺�ĵط���ʵ
�������Ҳ�ѹֵ���������ʦҪ�����ڴ��ˡ������е�һ����ɽ�ϣ�һ
����Ȫ��������������������������á�
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"houyuan2",  
		"south"  : __DIR__"zhongting", 
	]));
	set("objects",([ /* sizeof() == 1 */
		CLASS_D("lingxiao")+"/first" : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8860);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

