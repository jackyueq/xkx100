//Room: jietuopo.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","������");
      set("long",@LONG
�����Ƕ���ʤ�ؽ����¡�����һ��С�ţ��н����š��������ˣ���������
Ȫ�������������������������޽�٣��ļ����ѡ�����һ�����ã�����һƬ��
�֡�����ɽϪ�����ʵ������µ����档
LONG);
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"milin2",
          "westup"    : __DIR__"guanyintang",
      ]));
      set("objects",([ /* sizeof() == 1 */
          CLASS_D("emei")+"/guo" : 1,
      ]));
      set("outdoors", "emei");
	set("coor/x", -6060);
	set("coor/y", -1040);
	set("coor/z", 30);
	setup();
      replace_program(ROOM);
}