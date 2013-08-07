// Room: /d/yanziwu/hupan.c
// Date: Feb.14.1998 by Java

#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "̫������");
	set("long", @LONG
̫��(hu)������֮�䡣���������������֮ˮ�����ڴˣ��������
��ų����������������Ψ������Զ�������۽Ա̣���ʮ����Դ�ͦ
����������ǧ�겨��֮�У�ʹ���Ľ�󿪣�ֱ�����쳤Х�����ܱ��ϲ
�֡�
LONG );
	set("exits", ([
		"northeast" : "/d/suzhou/road5",
	]));
	set("item_desc", ([
		"hu":HIC"\n�����ϴ���һҶС�ۣ�����һ��������������Ϸˮ����("HIY"yell"HIC")һ�����԰ɡ�\n�������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤��������\n" NOR,
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("outdoors", "yanziwu");
	set("coor/x", 840);
	set("coor/y", -1140);
	set("coor/z", 0);
  set("yell_about", "����");             // yell ����
  set("river_type", "��");               // �����ϴ�������
  set("need_dodge",300);                 // ��Ҫ�����Ṧ
  set("come_msg_out",   "һβС�ۻ�����ʻ�˹�����һ��������Ů����������ۡ�\n");
  set("busy_msg",       "ֻ���ú�������������������������������\n");
  set("wait_msg",       "����һβС����һ��������Ůϸ��˵����ٯ��ɶ���塣\n");
  set("leave_msg_out",  "��Ů���һ�㣬С���밶����Ļ�ȥ��\n");
  set("leave_msg_in",   "\n��Ů˵��һ��������ඡ������������壬����һ��֮�£�˵���������ʡ�Ȼ�����һ�㣬��������Ļ�ȥ��\n");
  set("come_msg_in",    "��Ů˵: ���������ϰ��ɡ������漴һ����ݣ����۲��á�\n");
  set("item_desc/river", HIC "\n�����ϴ���һҶС�ۣ�����һ��������������Ϸˮ��Ҳ��("
                         HIY "yell" HIC ")һ������\n(" HIY "boat" HIC
                        ")�����������������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤��������\n" NOR);
  set("boat_short", "С��");    
  set("boat_desc",  @LONG
���̺���Ʈ����һҶС�ۣ�һ��������Ů��ִ˫����������ˮ����
�г�����ٯС���������������ǣ����ö��ġ�һ˫����������ӳ��
�̲�������͸��һ�㡣
LONG );
  set("to",         __DIR__"muti");  // �����յ� /*   ��ѡ   */
	setup();
}