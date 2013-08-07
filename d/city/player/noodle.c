//noodle.c
# include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
int do_saite();
void create()
{
	set_name("��а", ({ "noodle"}));
	set("gender", "����");
	set("long","   �����޶ۡ��������ǹ������꣬���جج�������ꡣ
   �˵����꣬ȴ�������������˼�����Ȥ����id��Ϊ����,�����½�ɫ������
����֮�½�ɫ������һ�α����У��¶�300����500��������ڣ���Ϊ˫�Ϲھ���
�ڴ��ڼ䣬ż��ֿ�����أ��Ӵ��������֣�Ц�����������������ڻ���������أ���
   �������꣬���ܲ�ͨϰ�ò���֮�������������Ϊ�飬Ϊ��Ϊ��
�书Ҳͻ���ͽ�����̨�����е��֡�ĳ������̨����һ֪������Ϊ����
Ψ�������������裬ʹ�������޽���֮���Ρ�
   ����һ��������bug���������ó����ճ�֮С�����з��ִ�bug��\n");
	set("title", HIW"ʥ��"NOR"����С�̽���"NOR"��ң�����Ŵ�ʦ��"NOR);
	set("nickname", HIW"��ϲ��bug"NOR);
	set("age", 46);
	set("class", "swordman");
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 30);
	set("int", 33);
	set("dex", 69);
	set("con", 41);
	set("str", 70);
	set("weiwang", 70);
	set("shen", 3);
	set("combat_exp", 16055317);
	set("PKS", 6);
	set("MKS", 30171);
	set("env/no_teach", "1");

	set("max_jing", 765);
	set("jing", 765);
	set("max_qi", 2436);
	set("qi", 2436);
	set("max_jingli", 740);
	set("jingli", 740);
	set("max_neili", 8130);
	set("neili", 8130);
	set("meili", 60);

	set_skill("literate", 542);
	set_skill("taoism", 200);
	set_skill("force", 542);
	set_skill("unarmed",542);
	set_skill("parry", 542);
	set_skill("dodge", 542);
	set_skill("staff", 542);
	set_skill("cuff", 542);
	set_skill("hand", 542);
	set_skill("claw", 542);
	set_skill("strike", 542);

	set_skill("hamagong", 542);
	set_skill("hamaquan", 542);
	set_skill("jiuyin-baiguzhao", 542);
	set_skill("kongming-quan", 542);
	set_skill("lingboweibu", 542);
	set_skill("lingshe-zhangfa", 542);
	set_skill("shexing-diaoshou", 542);

	map_skill("force", "hamagong");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	map_skill("unarmed","kongming-quan");
	map_skill("cuff","hamaquan");
	map_skill("strike","hamagong");
	map_skill("hand","shexing-diaoshou");
	map_skill("claw","jiuyin-baiguzhao");
	prepare_skill("claw","jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"�书"  : (: do_skills :),
		"����"  : (: do_saite :),
	]));

	create_family("��ң��",2, "����");
		
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_hp()
{
message_vision("$N˵�� �ҵĻ���״̬���£�\n\n"+
"�ԩ�������������������������������������������������������������\n"+
"�� �� �� ��  765/  765 (100��)   �� �� �� ��  740 /  740 (+0)\n"+
"�� �� Ѫ �� 2436/ 2436 (100��)   �� �� �� �� 8130 / 8130 (+0)\n"+
"�� �� �� ��       3              �� �� �� ��  340 /  340\n"+
"�� ʳ �� ��  262/  260           �� Ǳ �� ��  4409\n"+
"�� �� ˮ ��  260/  260           �� �� �� ��  16055317\n"+
"�ԩ�������������������������������������������������������������\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N˵�� �ҵĻ���״�����£�\n\n"+
"�� ����� ��ʥ������С�̽�����ң�����Ŵ�ʦ�֡���ϲ��bug����а(Noodle)\n"+
"\n"+
"  ����һλ��ʮ����ʮ�������Ը���ͨ���������࣬������һ��һ�ճ�ʱ��������\n"+
"  ����[16/ 70]  ����[30/ 84]  ����[19/ 73]  ��[15/ 69]  ����[15/ 69]\n"+
"  ����[10/ 30]  ��Ե[16/ 16]  ��ʶ[15/ 15]  ����[21/ 21]  ��ò[38/ 41]\n"+
"\n"+
" ���ʦ���� ���Ǻӡ� ��İ����� ���㡣\n"+
" ������һǧ�����������ƽ���ʮ��������ʮ����ͭǮ��\n"+
"\n"+
" <��>  ��������������������������������������������������\n"+
" <��>  ��������������������������������������������������\n"+
"\n"+
" ʳ���������������������������������������������������\n"+
" ��ˮ����������������������������������������������������\n"+
"\n"+
" ��ĿǰΪֹ���ܹ�ɱ�� 30171 ���ˣ������� 6 ����������ҡ�\n"+
" ��ĿǰΪֹ���ܹ�ɱ�� 1 ��ͬ�ţ������� 1 �������ʦ����\n"+
" ��ĿǰΪֹ���ܹ�ɱ�� 0 �����е��֣������� 0 ���������˾��\n"+
" ��ĿǰΪֹ���ܹ�ɱ�� 7882 ���޹����գ������� 204 ���Ƕ�ͯ��\n"+
" ��ĿǰΪֹ���ܹ����� 130 ���ˣ������� 11 ���Ƿ�����������\n"+
" ��ĿǰΪֹ���ܹ���ʦ�� 0 ���ˣ��������� 0 �Ρ�\n"+
"\n"+
" ��    ����        3     Ǳ    �ܣ� 4409 ( 99%)  ʵս���飺 16055317\n"+
" ��    ����       60     ����������     8432     ����������       70\n"+
"\n", this_object());
	return 1;
}
int do_skills()
{
command("secret noodle");
return 1;	
}
int do_saite()
{
message_vision("$N˵����ѽ�����ҵ������ǣ�����һ�����������ˡ����������������
��\n",this_object());
	return 1;
}