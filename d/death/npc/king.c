// king.c

#include <ansi.h>
inherit NPC;

string *answer_msg =({
"����������ƽ�յĻ��£���������յ�ĥ������������һ�Σ���ȥ�����йٰɡ�\n",
"�ţ���������Ѿ�����ˣ��ڹ�һ��ʱ��Ϳ����ˡ�\n",
"�����л���δϴ�壬���ܻؼҡ�",
"���������أ������ȵ��Űɡ�",
"�ߣ������ƺ��������ʵ�㣬����Щ��ɡ�",
"",//��һ������300���������С�
});
string ask_me();

void create()
{
	set_name(HIW "ۺ��ڤ�����" NOR, ({ "ming king","king" }) );
	set("long",HIW @LONG
�̩ɽ�����֮�Ⱥ��֮���������������ְ����������£�����������Ͻ������
����Ԧڤ��Ⱥ��
LONG NOR);
	set("gender","����");
	set("str",1000);
	set("nickname",HIR "����ڤ��" NOR);
	set("title",GRN"��"RED"��"YEL"��"BLU"ʥ"CYN"��"MAG"��"WHT"��"BLK"��"HIW"�������"NOR);            
	set("attitude", "peaceful");
	set("age", 102400000);
	set("combat_exp", 100000000);
	set("max_jing", 10000);
	set("max_qi", 10000);
	set("max_neili",100000);
	set("neili",100000);
	set("inquiry",([
		"�ؼ�":(:ask_me:),
	]) );
	setup();
}

string ask_me()
{
	int rein_time, mud_age, i;
	object who;
	who=this_player();
	if(who->query("age")<=15)
		return "�ף�����ôС��ͣ���ô���ܵ���������";
	mud_age=(int)who->query("mud_age");
	rein_time=(int)(who->query("PKS") * 20) + (int)(who->query("MKS") / 10);
	i=rein_time-mud_age;
	i=i>=0?i:0;
	i/=60;
	if(i>=4)
	{
		command("heng");
		i = 4;
	}
	else if(i<=0)
	{
		command("nod");
		i = 0; 
	}
	return answer_msg[i];
}
