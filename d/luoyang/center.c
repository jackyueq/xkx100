//  Room:  /d/luoyang/center.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��¥");
	set("long",  @LONG
һ����ִ���ש���Ĺ�����̨��¥�������ڳ����ġ���¥Ϊ����ľ
�߽��������д�Ĵ��ӣ�����ĺ�ģ����Ա�ʱ���������Ӹ���ߣ�����
�����ɣ��������Ժ�����÷�յ�ͼ���� 
    ��¥�����������Ķ���������Ĺ��ͺ��οͣ����������˹�������
�ʻ�����������ĵ���ģ�����������ȥ�ǽ��İ����º�����ʯ�߿�����
    ·�Ա߲����۵ĵط�����һ��ʯ��(bei)����������Щ����ˡ�
LONG);
	set("item_desc",  ([
		"bei" : "
    ����������ʱ���ǣ����������ء����ܡ�����������
κ����������κ����(쾵�)����(���)�����������ƵȾ�
���ʶ�����Ϊ�Ļ����ǣ��ߴ�Ŷ�֮һ��
\n",
	]));
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"eastroad",
		"west"  :  __DIR__"westroad",
		"south" :  __DIR__"southroad",
		"north" :  __DIR__"northroad",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
