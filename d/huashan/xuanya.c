// xuanya.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
���ǻ�ɽ�������ϵ�һƬƽ̨�������ն�ƽ̨�Ա���������Ԩ��
��ͷ���£�ֻ��һ���ƺ�����ɽ���Ӷ��ڴ���������������ʱ���ƣ���
���书��ƽʱ��ɽ����Ҳ�ڴ�ָ�㼰�������µ��ӡ�
LONG);
	set("exits",([
		"west" : __DIR__"houyuan",
	]));
	set("outdoors", "huashan");
	set("no_clean_up", 0);
	set("coor/x", -870);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
 
