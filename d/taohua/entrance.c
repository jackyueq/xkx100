// Room: /d/taohua/entrance.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�����Ǹ�̨�Ķ��㣬������һ�������ŵ����ݣ�ͨ��̫���㡣ǽ��
�Ϲ���һ�������ӣ����飺�������߲��û�ͷ�������Ը������������ͣ�
���ھ������ˡ��Ա���һ��˵��(shuoming)��
LONG
	);
	set("exits", ([ 
		"down" : __DIR__"taiji",
		"west" : __DIR__"hill2",
	]) );
	set("outdoors","taohua");
	set("item_desc", ([
		"shuoming" : "
�������
  ��һ��֮�������ǡ�����Ϊ���ν��ò㣬�����������������룬���������޷�����ͬ��
  ��һ��֮ʱ��������֪�����Ӧ��λ�����С�
  ��һ��֮�������С�������δ���룬��֮���������б������ԣ������ˣ��������ݡ�
                    ������δ���룬˥֮����ˡ��б������ԣ������ˣ��������ݡ�
                    �������룬��֮�󣬽Ծ����ݣ����ӣ�
"
	]) );

	set("no_clean_up", 0);
	set("coor/x", 8520);
	set("coor/y", -4680);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}